#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "SDL2/SDL.h"
#include "world.h"
#include "evenements.h"
#include "constante.h"

//gestion des evenements
void evenements(SDL_Event event, s_world_t* world, int nbLig, int nbCol) {
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                world->fin = true;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) { //evenements de type clavier
                    case SDLK_ESCAPE:
                        world->fin = true;
                        break; 
                    case SDLK_RIGHT: 
                        if (!collision_droit(world->sprite, world->tab, nbCol)) {
                            world->sprite->x += VITESSE;
                        }
                        break;  
                    case SDLK_LEFT:
                        if (!collision_gauche(world->sprite, world->tab)) {
                            world->sprite->x -= VITESSE;
                        }
                        break; 
                    case SDLK_SPACE:
                        if (!collision_haut(world->sprite, world->tab) && collision_bas(world->sprite, world->tab, nbLig)) {
                            world->sprite->y -= SAUT;                   
                        }
                        break;
                    default:
                        break;
                }
            default:
                break;
        }
    }
    deplacements_map(world, nbLig, nbCol);
}
