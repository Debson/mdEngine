#include "md_shader.h"



mdShader::mdShader() { }

mdShader::~mdShader() { }

mdShader::mdShader(const GLchar *vertexPath, const GLchar *fragmentPath, const GLchar *geometryPath)
{
	std::string vertexCode;
	std::string fragmentCode;
	std::string geometryCode;
	std::ifstream vShaderFile;
	std::ifstream fShaderFile;
	std::ifstream gShaderFile;
	vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	gShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try
	{
		vShaderFile.open(vertexPath);
		fShaderFile.open(fragmentPath);
		std::stringstream vShaderStream, fShaderStream;
		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();
		vShaderFile.close();
		fShaderFile.close();
		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();
		if (geometryPath != nullptr)
		{
			gShaderFile.open(geometryPath);
			std::stringstream gShaderStream;
			gShaderStream << gShaderFile.rdbuf();
			gShaderFile.close();
			geometryCode = gShaderStream.str();
		}
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ\n" << std::endl;
	}

	const GLchar* vShaderCode = vertexCode.c_str();
	const GLchar* fShaderCode = fragmentCode.c_str();

	GLuint vertex, fragment;
	int success;
	GLchar infoLog[512];
	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vShaderCode, NULL);
	glCompileShader(vertex);
	checkCompileErrors(vertex, "VERTEX");

	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fShaderCode, NULL);
	glCompileShader(fragment);
	checkCompileErrors(fragment, "FRAGMENT");

	GLuint geometry;
	if (geometryPath != nullptr)
	{
		const GLchar *gShaderCode = geometryCode.c_str();
		geometry = glCreateShader(GL_GEOMETRY_SHADER);
		glShaderSource(geometry, 1, &gShaderCode, NULL);
		glCompileShader(geometry);
		checkCompileErrors(geometry, "GEOMETRY");
		printf("\nGeometry!\n");
	}

	ID = glCreateProgram();
	glAttachShader(ID, vertex);
	glAttachShader(ID, fragment);
	if (geometryCode.empty() == false)
	{
		glAttachShader(ID, geometry);
	}
	glLinkProgram(ID);
	checkCompileErrors(ID, "PROGRAM");

	glDeleteShader(vertex);
	glDeleteShader(fragment);
	if (geometryCode.empty() == false)
	{
		glDeleteShader(geometry);
	}
}

void mdShader::use()
{
	glUseProgram(ID);
}

void mdShader::setBool(const std::string &name, GLboolean value) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}

void mdShader::setInt(const std::string &name, GLint value) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

void mdShader::setFloat(const std::string &name, GLfloat value) const
{
	glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}

void mdShader::checkCompileErrors(GLuint shader, std::string type)
{
	int success;
	GLchar infoLog[1024];

	if (type != "PROGRAM")
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "ERROR::SHADER_COMPILASTION_ERROR fo type: " << type << "\n" << infoLog << "\n ----" << std::endl;
		}
	}
	else
	{
		glGetProgramiv(shader, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n ----" << std::endl;
		}
	}
}

void mdShader::setVec2(const std::string &name, glm::vec2 &value) const
{
	glUniform2fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
}

void mdShader::setVec2(const std::string &name, GLfloat x, GLfloat y) const
{
	glUniform2f(glGetUniformLocation(ID, name.c_str()), x, y);
}

void mdShader::setVec3(const std::string &name, glm::vec3 value) const
{
	glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
}

void mdShader::setVec3(const std::string &name, GLfloat x, GLfloat y, GLfloat z) const
{
	glUniform3f(glGetUniformLocation(ID, name.c_str()), x, y, z);
}

void mdShader::setVec4(const std::string &name, glm::vec4 &value) const
{
	glUniform4fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
}

void mdShader::setVec4(const std::string &name, GLfloat x, GLfloat y, GLfloat z, GLfloat w) const
{
	glUniform4f(glGetUniformLocation(ID, name.c_str()), x, y, z, w);
}

void mdShader::setMat2(const std::string &name, glm::mat2 &mat) const
{
	glUniformMatrix2fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

void mdShader::setMat3(const std::string &name, glm::mat3 &mat) const
{
	glUniformMatrix3fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

void mdShader::setMat4(const std::string &name, glm::mat4 &mat, bool transpose) const
{
	glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, transpose ? GL_TRUE : GL_FALSE, &mat[0][0]);
}
