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
"uniform mat4 MVP;\n"
"attribute vec3 vCol;\n"
"attribute vec2 vPos;\n"
"varying vec3 color;\n"
"void main()\n"
"{\n"
"    gl_Position = MVP * vec4(vPos, 0.0, 1.0);\n"
"    color = vCol;\n"
"}\n";
static const char* vf =
"varying vec3 color;\n"
"void main()\n"
"{\n"
"    gl_FragColor = vec4(color, 1.0);\n"
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

	int vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex_shader, 1, &vs, NULL);
	glCompileShader(vertex_shader);

	int fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment_shader, 1, &vf, NULL);
	glCompileShader(fragment_shader);

	int	program = glCreateProgram();
    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);
    glLinkProgram(program);

	float vertices[] = {
		-0.5f, -0.5f, 0.0f, // left  
		 0.5f, -0.5f, 0.0f, // right 
		 0.0f,  0.5f, 0.0f  // top   
	};

	unsigned int	vao;
	unsigned int	vbo;

	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);

	glBindVertexArray(vao);

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
		glDrawArrays(GL_TRIANGLES, 0, 3);
	
		glfwSwapBuffers(env.window);
		glfwPollEvents();
	}
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
	glfwDestroyWindow(env.window);
	glfwTerminate();
	return 0;
}
