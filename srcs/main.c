/* ****************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:22:49 by notraore          #+#    #+#             */
/*   Updated: 2018/12/05 17:22:50 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

bool	parse_obj_files(int fd, char *line)
{

	return (true);
}

int		main(int argc, char **argv)
{
	SDL_Window		*win;
	SDL_Event		event;
	SDL_GLContext	contexteOpenGL;
	bool			end;
	float vertex[] = {0.0, 0.0,   0.5, 0.0,   0.0, 0.5,
		-0.3, 0.3,   -0.3, -0.8,   -0.8, -0.3};

	end = false;
	/* Version OpenGL */
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 4);
	/* Double buffering */
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		ft_putstr("error whine init SDL");
		SDL_Quit();
		return (-1);
	}

	/*Creation de la fenetre*/
	win = SDL_CreateWindow("Test SDL 2.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

	if (!win)
		ft_kill("error while creating window");
	contexteOpenGL = SDL_GL_CreateContext(win);
	if (contexteOpenGL == 0)
	{
		ft_putendl("context failed : ");
		ft_putendl(SDL_GetError());
		SDL_DestroyWindow(win);
		SDL_Quit();
	}
	/*Loop du programme*/
	while (end == false)
	{
		SDL_WaitEvent(&event);
		if (event.type == SDL_QUIT)
			end = true;
		/*Clear la fenetre pour l'actualiser*/
		glClear(GL_COLOR_BUFFER_BIT);
		/**/
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, vertex);
        glEnableVertexAttribArray(0);
        /*Dessiner les vertexes ; GL_TRIANGLE_FAN est une facon de dessiner des triangles connectes entre-eux s'ils ont un ou deux points identiques*/
        glDrawArrays(GL_TRIANGLE_FAN, 0,5);

        glDisableVertexAttribArray(0);
        
		SDL_GL_SwapWindow(win);
	}
	SDL_GL_DeleteContext(contexteOpenGL);
	SDL_DestroyWindow(win);
	SDL_Quit();
	return 0;
}
