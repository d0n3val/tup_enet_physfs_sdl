#include "version.h"
#include "SDL.h"
#include "physfs.h"
#include "enet/enet.h"

int main(int argc, char* argv[])
{
	// Our version ----------------
	printf("My version is version %i.%i-%i -%s (%s)\n", 
			VER_MAJOR, VER_MINOR, 
			VER_PATCH, VER_TUP_PLATFORM, 
			VER_COMPILATION_TYPE);

	// SDL version ----------------
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_version sdl_version;
	SDL_GetVersion(&sdl_version);


	printf("SDL Version %i.%i-%i\n", 
			sdl_version.major, sdl_version.minor, sdl_version.patch);

	SDL_Quit();
	
	// Physfs version ----------------
	PHYSFS_init(argv[0]);
	PHYSFS_Version physfs_version;
	PHYSFS_VERSION(&physfs_version);

	printf("Physfs Version %i.%i-%i\n", 
			physfs_version.major, physfs_version.minor, physfs_version.patch);

	PHYSFS_deinit();

	// Enet version ----------------
	ENetVersion enet_version = ENET_VERSION;

	printf("Enet Version %i.%i-%i\n", 
			ENET_VERSION_GET_MAJOR(enet_version), ENET_VERSION_GET_MINOR(enet_version), ENET_VERSION_GET_PATCH(enet_version) );

	return(0);
}
