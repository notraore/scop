/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <notraore@student.42.fr>           +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 12:26:12 by notraore          #+#    #+#             */
/*   Updated: 2019/02/18 21:14:52 by notraore             ###   ########.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	(void)window;
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}

static const char* vs =
"#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"

"void main()\n"
"{\n"
    "gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\n";

static const char* vf =
"#version 330 core\n"
"out vec4 FragColor;\n"

"void main()\n"
"{\n"
    "FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n";



void				input_key(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

void				win_update(void *f(float), GLFWwindow *win)
{
	double last;
	double now;
	double delta = 0.01f;

	last = glfwGetTime();
	(*f)(delta);
	glfwSwapBuffers(win);
	glfwPollEvents();

	now = glfwGetTime();
	delta = (now - last) * 10.0f;
}

int					checkShader(GLuint shader, GLint compiled)
{
	if (!compiled)
	{
		GLint infoLen = 0;

		glGetShaderiv (shader, GL_INFO_LOG_LENGTH, &infoLen);

		if (infoLen > 1)
		{
			char *infoLog = malloc (sizeof(char) * infoLen );
         	glGetShaderInfoLog (shader, infoLen, NULL, infoLog );
        	printf( "Error compiling shader:\n%s\n", infoLog );            
        	free ( infoLog );
     	}
    	glDeleteShader (shader);
     	return 0;
	}
	return (1);
}

int					checkProgram(GLuint program, GLint compiled)
{
	if ( !compiled ) 
   {
	  GLint infoLen = 0;
      glGetProgramiv ( program, GL_INFO_LOG_LENGTH, &infoLen );
      
      if ( infoLen > 1 )
      {
         char *infoLog2 = malloc (sizeof(char) * infoLen );

         glGetProgramInfoLog ( program, infoLen, NULL, infoLog2 );
         printf( "Error linking program:\n%s\n", infoLog2 );            
         
         free ( infoLog2 );
      }

      glDeleteProgram ( program );
      return 0;
   }
   return (1);
}

int					main(void)
{
	if (!glfwInit())
		ft_kill("Can't init GLFW.");

	t_glenv		env;
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	env.window = glfwCreateWindow(980, 980, "Scop - 42", NULL, NULL);
	if (!env.window)
		ft_kill("Can't create window.");
	glfwMakeContextCurrent(env.window);
	glfwSetFramebufferSizeCallback(env.window, framebuffer_size_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
	   ft_putendl("Failed to initialize GLAD");
		return -1;
	}

	GLint compiled;
	GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	if (vertex_shader == 0 )
		ft_kill("shader not created");
	
	glShaderSource(vertex_shader, 1, &vs, NULL);
	glCompileShader(vertex_shader);
	glGetShaderiv (vertex_shader, GL_COMPILE_STATUS, &compiled );

	if (!checkShader(vertex_shader, compiled))
		ft_kill("Shader compilation failed");

	GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment_shader, 1, &vf, NULL);
	glCompileShader(fragment_shader);
	glGetShaderiv (fragment_shader, GL_COMPILE_STATUS, &compiled );

	if (!checkShader(fragment_shader, compiled))
		ft_kill("Shader compilation failed");

	GLuint	program = glCreateProgram();

	if ( program == 0 )
      ft_kill("Program error not created");
	
    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);
    glLinkProgram(program);

	glGetProgramiv ( program, GL_LINK_STATUS, &compiled );

	if (!checkProgram(program, compiled))
	{
		ft_kill("Program compilation failed");
	}
   

	float vertices[] = {
		0.5f,  0.5f, 0.0f,  // top right
		0.5f, -0.5f, 0.0f,  // bottom right
		-0.5f, -0.5f, 0.0f,  // bottom left
		-0.5f,  0.5f, 0.0f   // top left 
	};

	unsigned int indices[] = {  // note that we start from 0!
		0, 1, 3,   // first triangle
		1, 2, 3    // second triangle
	};  
	
	unsigned int	vao;
	unsigned int	vbo;
	unsigned int	ebo;

	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ebo);
	glBindVertexArray(vao);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0); 

	glBindVertexArray(0);

	// parse_shader("./basic.shader");

	double		current_time;
	double		last_time;
	int			frames;
	last_time = glfwGetTime();
	frames = 0;
	while (!glfwWindowShouldClose(env.window))
	{
		input_key(env.window);
		current_time = glfwGetTime();
		frames++;
		if (current_time - last_time >= 0.2f)
		{
			ft_putnbr(frames);
			ft_putendl(" FPS");
			frames = 0;
			last_time += 1.0;
		}
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(program);
		glBindVertexArray(vao);
		// glDrawArrays(GL_TRIANGLES, 0, 6);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

		glfwSwapBuffers(env.window);
		glfwPollEvents();
	}
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
	glfwDestroyWindow(env.window);
	glfwTerminate();
	return 0;
}
