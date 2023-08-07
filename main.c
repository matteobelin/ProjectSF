
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL_ttf.h>

void affichage(SDL_Texture* textureFond, SDL_Texture* textureSpriteDebout, SDL_Texture* textureSpriteDebout2, SDL_Texture* avancer1, SDL_Texture* avancer2, SDL_Texture* avancer3, SDL_Texture* avancer4,
    SDL_Texture* avancer5, SDL_Texture* accroupis, SDL_Texture* saut1, SDL_Texture* saut2, SDL_Texture* saut3, SDL_Texture* saut4, SDL_Texture* saut5, SDL_Texture* saut6,
    SDL_Texture* coupDebout1, SDL_Texture* coupDebout2, SDL_Texture* coupDebout3, SDL_Texture* coupAccroupis1, SDL_Texture* coupAccroupis2, SDL_Texture* coupAccroupis3, SDL_Texture* coupPied1,
    SDL_Texture* coupPied2, SDL_Texture* coupPied3, SDL_Texture* deboutBot, SDL_Renderer* renderer, SDL_Rect* barreDeVie, SDL_Rect* barreDeVieDroite, SDL_Rect* barreDeVieRed,
    SDL_Rect* barreDeVieRedDroite, SDL_Rect* destRectDebout, SDL_Rect* destRectAccroupis, SDL_Rect* destRectCoupDebout, SDL_Rect* destRectCoupAccroupris, SDL_Rect* destRectBot1,
    SDL_Rect* rectangleCoup, int* psnick, int* pcoup, int* pcoupPied, int* pcompteur, int* pavancer, int* pcompteurAvancer, int* pcompteursaut, int* psaut, TTF_Font* font,
    const char* text, int x, int y, SDL_Color* colortimer)// est définie pour dessiner les éléments du jeu sur la fenêtre. Elle prend en paramètre la texture à afficher, le renderer, les rectangles de base et de coup, et le coup choisit.
{

    SDL_Surface* surface_timer = TTF_RenderText_Solid(font, text, *colortimer);
    if (!surface_timer)
    {
        printf("Erreur de rendu du texte: %s\n", TTF_GetError());
        return;
    }
    SDL_Texture* texture_timer = SDL_CreateTextureFromSurface(renderer, surface_timer);
    SDL_Rect rect = { x, y, surface_timer->w, surface_timer->h };

    if (!textureFond)
    {
        printf("Erreur de création de la texture: %s\n", SDL_GetError());
        SDL_FreeSurface(surface_timer);
        return;
    }
    SDL_RenderClear(renderer); // efface le rendu
    SDL_RenderCopy(renderer, textureFond, NULL, NULL); // charge la texture sur le rendu
    SDL_RenderCopy(renderer, deboutBot, NULL, destRectBot1);// charge la texture qui sera mise aux coordonée de destRectBot1
    if (*psaut == 1 || *psaut == 2)
    {
        if (*pcompteursaut < 10) // permet de gerer l'animation compte le nombre de fois ou rentre dans la fonction pour gérer affichage
        {
            SDL_RenderCopy(renderer, saut1, NULL, destRectDebout);// charge la texture qui sera mise aux coordonée de destRectDebout
            *pcompteursaut += 1;
        }
        else if (*pcompteursaut < 40)
        {
            SDL_RenderCopy(renderer, saut2, NULL, destRectDebout);
            *pcompteursaut += 1;
        }
        else if (*pcompteursaut < 80)
        {
            SDL_RenderCopy(renderer, saut3, NULL, destRectDebout);
            *pcompteursaut += 1;
        }
        else if (*pcompteursaut < 100)
        {
            SDL_RenderCopy(renderer, saut4, NULL, destRectDebout);
            *pcompteursaut += 1;
        }
        else if (*pcompteursaut < 140)
        {
            SDL_RenderCopy(renderer, saut5, NULL, destRectDebout);
            *pcompteursaut += 1;
        }
        else if (*pcompteursaut < 200)
        {
            SDL_RenderCopy(renderer, saut6, NULL, destRectDebout);
            *pcompteursaut += 1;
        }
        else if (*pcompteursaut < 240)
        {
            SDL_RenderCopy(renderer, saut1, NULL, destRectDebout);
            *pcompteursaut += 1;
        }
    }


    else if (*pcoup != 0 && *psnick == 0)
    {
        if (rectangleCoup->w < 50)//rectangleCoup->w = rectangleCoup.w pour les pointeurs
        {
            SDL_RenderCopy(renderer, coupDebout1, NULL, destRectDebout);
        }
        else if (rectangleCoup->w > 160)
        {
            SDL_RenderCopy(renderer, coupDebout3, NULL, destRectCoupDebout);
        }
        else if (rectangleCoup->w > 30)
        {
            SDL_RenderCopy(renderer, coupDebout2, NULL, destRectDebout);
        }

    }
    else if (*pcoupPied != 0)
    {
        if (rectangleCoup->w < 50)
        {
            SDL_RenderCopy(renderer, coupPied1, NULL, destRectDebout);
        }
        else if (rectangleCoup->w > 160)
        {
            SDL_RenderCopy(renderer, coupPied3, NULL, destRectCoupDebout);
        }
        else if (rectangleCoup->w > 30)
        {
            SDL_RenderCopy(renderer, coupPied2, NULL, destRectDebout);
        }

    }
    else if (*pcoup != 0 && *psnick == 1)
    {
        if (rectangleCoup->w < 50)
        {
            SDL_RenderCopy(renderer, coupAccroupis1, NULL, destRectAccroupis);
        }
        else if (rectangleCoup->w > 140)
        {
            SDL_RenderCopy(renderer, coupAccroupis3, NULL, destRectCoupAccroupris);
        }
        else if (rectangleCoup->w > 30)
        {
            SDL_RenderCopy(renderer, coupAccroupis2, NULL, destRectAccroupis);
        }
    }

    else if (*pavancer == 1 && *psnick == 0)
    {
        if (*pcompteurAvancer < 20) // permet de gerer l'animation compte le nombre de fois ou rentre dans la fonction pour gérer affichage
        {
            SDL_RenderCopy(renderer, avancer1, NULL, destRectDebout);
            *pcompteurAvancer += 1;
        }
        else if (*pcompteurAvancer < 40)
        {
            SDL_RenderCopy(renderer, avancer2, NULL, destRectDebout);
            *pcompteurAvancer += 1;
        }
        else if (*pcompteurAvancer < 60)
        {
            SDL_RenderCopy(renderer, avancer3, NULL, destRectDebout);
            *pcompteurAvancer += 1;
        }
        else if (*pcompteurAvancer < 80)
        {
            SDL_RenderCopy(renderer, avancer4, NULL, destRectDebout);
            *pcompteurAvancer += 1;
        }
        else if (*pcompteurAvancer < 120)
        {
            SDL_RenderCopy(renderer, avancer5, NULL, destRectDebout);
            *pcompteurAvancer += 1;
            if (*pcompteurAvancer == 120)
            {
                *pcompteurAvancer = 0;
            }
        }
    }
    else if (*psnick == 1)
    {
        SDL_RenderCopy(renderer, accroupis, NULL, destRectAccroupis);
    }
    else
    {
        if (*pcompteur < 80)
        {
            SDL_RenderCopy(renderer, textureSpriteDebout, NULL, destRectDebout);
            *pcompteur += 1;
        }
        else
        {
            SDL_RenderCopy(renderer, textureSpriteDebout2, NULL, destRectDebout);
            *pcompteur += 1;
            if (*pcompteur == 160)
            {
                *pcompteur = 0;
            }
        }
    }
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);// choisit la couleur
    SDL_RenderFillRect(renderer, barreDeVieRed);// dessine le rectangle en plein pour la couleur choisit ( SDL_RenderDrawRect rectangle vide,SDL_RenderFillRect rectangle plein)
    SDL_RenderFillRect(renderer, barreDeVieRedDroite);
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(renderer, barreDeVie);
    SDL_RenderFillRect(renderer, barreDeVieDroite);

    SDL_RenderCopy(renderer, texture_timer, NULL, &rect);

    SDL_DestroyTexture(texture_timer);
    SDL_RenderPresent(renderer);// affiche le rendu
}


void hitCheck(int* pcoup, int* pstrikeSpeed, int* pcoupPied, int* pdegat, SDL_Rect* rectanglePunchingBall, SDL_Rect* rectangleCoup, SDL_Rect* barreDeVieDroite)
{
    if ((*pcoup == 1 || *pcoup == 5 || *pcoupPied == 1) && ((rectangleCoup->x + rectangleCoup->w) >= rectanglePunchingBall->x) && *pstrikeSpeed == 0 && *pdegat == 0)
    {
        barreDeVieDroite->x += 15;
        barreDeVieDroite->w -= 15;
        *pdegat = 1;// permet de mettre une seul fois le degat par coup touche
    }
    else if ((*pstrikeSpeed == 2) && ((rectangleCoup->x + rectangleCoup->w) >= rectanglePunchingBall->x) && *pdegat == 0)
    {

        barreDeVieDroite->x += 20;
        barreDeVieDroite->w -= 20;
        *pdegat = 1;
    }
    else if ((*pstrikeSpeed == 1) && ((rectangleCoup->x + rectangleCoup->w) >= rectanglePunchingBall->x) && *pdegat == 0)
    {

        barreDeVieDroite->x += 40;
        barreDeVieDroite->w -= 40;
        *pdegat = 1;
    }
}

void win(SDL_Rect* rectanglePerso1, SDL_Texture* texture, SDL_Texture* win1, SDL_Texture* win2, SDL_Texture* win3, SDL_Renderer* renderer, SDL_Rect* destRectDebout, SDL_Rect* destRectwin3
    , int* petapeWin, int* pcompteurWin)
{
    if (rectanglePerso1->y != 500)   // rectangle->y == rectangle.y different car pointeur
    {
        rectanglePerso1->y = 500;
        rectanglePerso1->h = 500;

    }
    SDL_RenderClear(renderer);// efface le rendu
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    if (*petapeWin == 0)
    {
        SDL_RenderCopy(renderer, win1, NULL, destRectDebout);// charge la texture qui sera mise aux coordonée de destRectDebout
        *pcompteurWin += 1;
        if (*pcompteurWin > 100)   // permet de gerer l'animation compte le nombre de fois ou rentre dans la fonction pour gérer affichage
        {
            *petapeWin = 1;
        }
    }
    else if (*petapeWin == 1)
    {
        SDL_RenderCopy(renderer, win2, NULL, destRectDebout);
        *pcompteurWin += 1;
        if (*pcompteurWin > 150)
        {
            *petapeWin = 2;
        }
    }
    else
    {
        SDL_RenderCopy(renderer, win3, NULL, destRectwin3);
    }
    SDL_RenderPresent(renderer);// affiche le rendu
}

Uint32 timer_callback(Uint32 interval, void* param)
{
    int* minuteur = (int*)param;
    (*minuteur)--;
    return (0 < *minuteur) ? interval : 0;
}

void destructionTexture(SDL_Texture* textureSpriteDebout2, SDL_Texture* textureSpriteDebout, SDL_Texture* avancer1, SDL_Texture* avancer2, SDL_Texture* avancer3, SDL_Texture* avancer4, SDL_Texture* avancer5,
    SDL_Texture* accroupis, SDL_Texture* saut1, SDL_Texture* saut2, SDL_Texture* saut3, SDL_Texture* saut4, SDL_Texture* saut5, SDL_Texture* saut6, SDL_Texture* coupDebout1, SDL_Texture* coupDebout2,
    SDL_Texture* coupDebout3, SDL_Texture* coupAccroupis1, SDL_Texture* coupAccroupis2, SDL_Texture* coupAccroupis3, SDL_Texture* coupPied1, SDL_Texture* coupPied2, SDL_Texture* coupPied3, SDL_Texture* deboutBot,
    SDL_Texture* win1, SDL_Texture* win2, SDL_Texture* win3, SDL_Texture* textureFond, SDL_Renderer* renderer, SDL_Window* pwindow)
{


    SDL_DestroyTexture(textureSpriteDebout2);// detruit la texture
    SDL_DestroyTexture(textureSpriteDebout);
    SDL_DestroyTexture(avancer1);
    SDL_DestroyTexture(avancer2);
    SDL_DestroyTexture(avancer3);
    SDL_DestroyTexture(avancer4);
    SDL_DestroyTexture(avancer5);
    SDL_DestroyTexture(accroupis);
    SDL_DestroyTexture(saut1);
    SDL_DestroyTexture(saut2);
    SDL_DestroyTexture(saut3);
    SDL_DestroyTexture(saut4);
    SDL_DestroyTexture(saut5);
    SDL_DestroyTexture(saut6);
    SDL_DestroyTexture(coupDebout1);
    SDL_DestroyTexture(coupDebout2);
    SDL_DestroyTexture(coupDebout3);
    SDL_DestroyTexture(coupAccroupis1);
    SDL_DestroyTexture(coupAccroupis2);
    SDL_DestroyTexture(coupAccroupis3);
    SDL_DestroyTexture(coupPied1);
    SDL_DestroyTexture(coupPied2);
    SDL_DestroyTexture(coupPied3);
    SDL_DestroyTexture(deboutBot);
    SDL_DestroyTexture(win1);
    SDL_DestroyTexture(win2);
    SDL_DestroyTexture(win3);
    SDL_DestroyTexture(textureFond);
    SDL_DestroyRenderer(renderer);// detruit le rendu
    SDL_DestroyWindow(pwindow); // Detruit la fenetre

}



void jeu(int* pjouer)
{
    SDL_Window* pwindow;
    SDL_Renderer* renderer;
    Uint8 const* toucheScancode;
    SDL_Event touche;
    SDL_Rect rectanglePerso1 = { 20, 500, 220, 500 };// {x,y,w,h}
    SDL_Rect rectangleCoup = { 0, 0, 0, 100 };
    SDL_Rect rectanglePunchingBall = { 1600, 500, 220, 500 };
    SDL_Rect barreDeVie = { 80, 80, 700, 40 };
    SDL_Rect barreDeVieRed = { 80, 80, 700,40 };
    SDL_Rect barreDeVieDroite = { 1180, 80, 680,40 };
    SDL_Rect barreDeVieRedDroite = { 1180, 80, 680,40 };

    SDL_Rect destRectDebout;
    SDL_Rect destRectAccroupis;
    SDL_Rect destRectCoupDebout;
    SDL_Rect destRectCoupAccroupris;
    SDL_Rect destRectBot1;
    SDL_Rect destRectwin3;
    SDL_Texture* textureFond;
    SDL_Texture* textureSpriteDebout;
    SDL_Texture* textureSpriteDebout2;
    SDL_Texture* avancer1;
    SDL_Texture* avancer2;
    SDL_Texture* avancer3;
    SDL_Texture* avancer4;
    SDL_Texture* avancer5;
    SDL_Texture* accroupis;
    SDL_Texture* saut1;
    SDL_Texture* saut2;
    SDL_Texture* saut3;
    SDL_Texture* saut4;
    SDL_Texture* saut5;
    SDL_Texture* saut6;
    SDL_Texture* coupDebout1;
    SDL_Texture* coupDebout2;
    SDL_Texture* coupDebout3;
    SDL_Texture* coupAccroupis1;
    SDL_Texture* coupAccroupis2;
    SDL_Texture* coupAccroupis3;
    SDL_Texture* coupPied1;
    SDL_Texture* coupPied2;
    SDL_Texture* coupPied3;
    SDL_Texture* deboutBot;
    SDL_Texture* win1;
    SDL_Texture* win2;
    SDL_Texture* win3;
    SDL_Event evenement;
    SDL_Color color_timer = { 0, 0, 0 };

    int minuteur ; 
    int jeu ;
    int saut ;
    int snick;
    int coup ;
    int coupPied ;
    int strikeSpeed ;
    int compteur ;
    int avancer ;
    int compteurAvancer ;
    int compteurSaut ;
    int side ;
    int degat ;
    int etape ;
    int compteurWin ;
    char timer_text[20];



    minuteur = 180; // 3 minutes en secondes
    jeu = 0;
    saut = 0;
    snick = 0;
    coup = 0;
    coupPied = 0;
    strikeSpeed = 0;
    compteur = 0;
    avancer = 0;
    compteurAvancer = 0;
    compteurSaut = 0;
    side = 1;
    degat = 0;
    etape = 0;
    compteurWin = 0;

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
    SDL_version nb;
    SDL_VERSION(&nb);
    pwindow = SDL_CreateWindow("test", SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        1920,
        1080,
        SDL_WINDOW_FULLSCREEN);// Cree la fenêtre de dimension 1920px par 1080px en fullscreen

    renderer = SDL_CreateRenderer(pwindow, -1, SDL_RENDERER_SOFTWARE); // creer un rendu
    textureFond = IMG_LoadTexture(renderer, "C:/Users/Public/SFBackground.bmp"); // telecharger la texture (IMG_LoadTexture besoin de SLD_Image)
    textureSpriteDebout = IMG_LoadTexture(renderer, "C:/Users/Public/Debout.png");
    textureSpriteDebout2 = IMG_LoadTexture(renderer, "C:/Users/Public/Debout2.png");
    avancer1 = IMG_LoadTexture(renderer, "C:/Users/Public/avancer1.png");
    avancer2 = IMG_LoadTexture(renderer, "C:/Users/Public/avancer2.png");
    avancer3 = IMG_LoadTexture(renderer, "C:/Users/Public/avancer3.png");
    avancer4 = IMG_LoadTexture(renderer, "C:/Users/Public/avancer4.png");
    avancer5 = IMG_LoadTexture(renderer, "C:/Users/Public/avancer5.png");
    accroupis = IMG_LoadTexture(renderer, "C:/Users/Public/accroupis.png");
    saut1 = IMG_LoadTexture(renderer, "C:/Users/Public/saut1.png");
    saut2 = IMG_LoadTexture(renderer, "C:/Users/Public/saut2.png");
    saut3 = IMG_LoadTexture(renderer, "C:/Users/Public/saut3.png");
    saut4 = IMG_LoadTexture(renderer, "C:/Users/Public/saut4.png");
    saut5 = IMG_LoadTexture(renderer, "C:/Users/Public/saut5.png");
    saut6 = IMG_LoadTexture(renderer, "C:/Users/Public/saut6.png");
    coupDebout1 = IMG_LoadTexture(renderer, "C:/Users/Public/coupDebout1.png");
    coupDebout2 = IMG_LoadTexture(renderer, "C:/Users/Public/coupDebout2.png");
    coupDebout3 = IMG_LoadTexture(renderer, "C:/Users/Public/coupDebout3.png");
    coupAccroupis1 = IMG_LoadTexture(renderer, "C:/Users/Public/coupAccroupis1.png");
    coupAccroupis2 = IMG_LoadTexture(renderer, "C:/Users/Public/coupAccroupis2.png");
    coupAccroupis3 = IMG_LoadTexture(renderer, "C:/Users/Public/coupAccroupis3.png");
    coupPied1 = IMG_LoadTexture(renderer, "C:/Users/Public/coupPied1.png");
    coupPied2 = IMG_LoadTexture(renderer, "C:/Users/Public/coupPied2.png");
    coupPied3 = IMG_LoadTexture(renderer, "C:/Users/Public/coupPied3.png");
    deboutBot = IMG_LoadTexture(renderer, "C:/Users/Public/deboutBot.png");
    win1 = IMG_LoadTexture(renderer, "C:/Users/Public/win1.png");
    win2 = IMG_LoadTexture(renderer, "C:/Users/Public/win2.png");
    win3 = IMG_LoadTexture(renderer, "C:/Users/Public/win3.png");



    destRectBot1.x = rectanglePunchingBall.x;// le rectangle ou on va afficher le sprite prend la valeur du rectangle de la hitbox punchingball
    destRectBot1.y = rectanglePunchingBall.y;

    SDL_QueryTexture(textureSpriteDebout, NULL, NULL, &destRectDebout.w, &destRectDebout.h);// permet que la hauteur et la largeur du rectangle correspondent a celle du sprite
    SDL_QueryTexture(accroupis, NULL, NULL, &destRectAccroupis.w, &destRectAccroupis.h);
    SDL_QueryTexture(coupDebout3, NULL, NULL, &destRectCoupDebout.w, &destRectCoupDebout.h);
    SDL_QueryTexture(coupAccroupis3, NULL, NULL, &destRectCoupAccroupris.w, &destRectCoupAccroupris.h);
    SDL_QueryTexture(deboutBot, NULL, NULL, &destRectBot1.w, &destRectBot1.h);
    SDL_QueryTexture(win3, NULL, NULL, &destRectwin3.w, &destRectwin3.h);

    SDL_RenderClear(renderer); // efface le rendu

    SDL_RenderCopy(renderer, textureFond, NULL, NULL);// charge la texture sur le rendu


    SDL_RenderPresent(renderer);//affiche un rendu


    if (TTF_Init() < 0)
    {
        printf("Erreur d'initialisation de SDL_ttf: %s\n", TTF_GetError());
        SDL_Quit();
    }
    TTF_Font* font = TTF_OpenFont("C:/Users/Public/Font.ttf", 50);
    SDL_TimerID timer_id = SDL_AddTimer(1000, timer_callback, &minuteur);







    while (jeu == 0)
    {

        // Afficher le minuteur ici, en utilisant SDL_ttf

        snprintf(timer_text, sizeof(timer_text), "%02d:%02d", minuteur / 60, minuteur % 60);/*snprint sert formater une chaine de caractere, 
        "%02d:%02d" signifie que la forme du timer doit etre retourne sous un entier de minimum 2 caractere en remplissant les espacs vides avec des 0*/ 





        toucheScancode = SDL_GetKeyboardState(NULL); // récupérer l'état des touches du clavier

        if (toucheScancode[SDL_SCANCODE_D] && (coup == 0) && (coupPied == 0) && snick == 0 && compteurWin == 0) // aller a gauche
        {
            if (rectanglePerso1.x < 1680)
            {
                if (snick == 0)
                {
                    rectanglePerso1.x += 2;
                }
                if (saut == 1)
                {
                    rectanglePerso1.x += 1;
                }
                side = 1;
            }
            avancer = 1;
        }

        if (toucheScancode[SDL_SCANCODE_A] && (coup == 0) && (coupPied == 0) && snick == 0 && compteurWin == 0) // aller a gauche
        {

            if (rectanglePerso1.x > 20)
            {
                if (snick == 0)
                {
                    rectanglePerso1.x -= 2;
                }
                if (saut == 1)
                {
                    rectanglePerso1.x -= 1;
                }
            }
            avancer = 1;

        }

        if ((toucheScancode[SDL_SCANCODE_S]) && (saut == 0) && (coup == 0) && (coupPied == 0)) // quand on appui sur la touche pour se baisser
        {
            rectanglePerso1.y = 700;
            rectanglePerso1.h = 300;
            snick = 1;
        }
        if ((toucheScancode[SDL_SCANCODE_W]) && (saut == 0) && (snick == 0) && (coup == 0) && (coupPied == 0))// quand on appui sur la touche pour sauter
        {
            if (rectanglePerso1.y > 130)
            {
                saut = 1;
            }
            else
            {
                saut = 2;
            }

        }


        if (saut == 1)
        {
            if (rectanglePerso1.y < 130)// permet qu'une fois qu'il est a cette hauteur le perso redescende
            {
                saut = 2;
            }
            rectanglePerso1.y -= 4;
        }
        if (saut == 2)
        {
            if (rectanglePerso1.y < 500)
            {
                rectanglePerso1.y += 4;
            }
            else if (rectanglePerso1.y == 500)
            {
                saut = 0;
                compteurSaut = 0;
            }
        }


        if ((toucheScancode[SDL_SCANCODE_S] == 0) && (snick == 1) && (saut == 0) && (coup == 0)) // quand on lache la touche pour se relever
        {
            rectanglePerso1.y = 500;
            rectanglePerso1.h = 500;
            snick = 0;
            avancer = 0;
            compteurAvancer = 0;
        }


        if (((toucheScancode[SDL_SCANCODE_C]) || (toucheScancode[SDL_SCANCODE_Q]) || (toucheScancode[SDL_SCANCODE_E]) || ((toucheScancode[SDL_SCANCODE_R] && snick == 0))) && (saut == 0))
        {

            if (toucheScancode[SDL_SCANCODE_Q])
            {
                strikeSpeed = 1; // correspond a coup lent
            }
            if (toucheScancode[SDL_SCANCODE_E])
            {
                strikeSpeed = 2; // correspond a coup moyen
            }
            if ((toucheScancode[SDL_SCANCODE_R]) && (side == 1) && (snick == 0))
            {
                coupPied = 1; // correspond a coup pied
                side = 3;
            }

            else if ((side == 1) && (snick == 0))
            {
                coup = 1;
                side = 3;// Pour pas qu'il repasse a coup 1
            }

            else if ((side == 1) && (snick == 1))
            {
                coup = 5;
                side = 3; // Pour pas qu'il repasse a coup 5
            }


        }



        if ((coup == 1) && (saut == 0))   // coup de poing haut
        {
            rectangleCoup.h = 80;
            rectangleCoup.x = rectanglePerso1.x + rectanglePerso1.w;// permet de commencer le rectangle coup sur la partie droite du rectangle
            rectangleCoup.y = rectanglePerso1.y + 80; // gerer la position du coup en fonction des ordonnées (inversé en SDL 0 en haut a gauche)
            if (rectangleCoup.w > 220)
            {
                coup = 2;
            }
            if (strikeSpeed == 1)
            {
                rectangleCoup.w += 2;
            }
            else if (strikeSpeed == 2)
            {
                rectangleCoup.w += 3;
            }
            else
            {
                rectangleCoup.w += 4;
            }

        }
        if ((coup == 2) && (saut == 0))   // retour coup de point haut
        {
            if (strikeSpeed == 1)
            {
                rectangleCoup.w -= 2;
            }
            else if (strikeSpeed == 2)
            {
                rectangleCoup.w -= 3;
            }
            else
            {
                rectangleCoup.w -= 4;
            }
            if (rectangleCoup.w <= 0)
            {
                coup = 0;
                side = 1;
                strikeSpeed = 0;
                degat = 0;
            }
        }

        if ((coup == 5) && (saut == 0))    // coup de point bas 
        {
            rectangleCoup.h = 60;
            rectangleCoup.x = rectanglePerso1.x + rectanglePerso1.w;// permet de commencer le rectangle coup sur la partie droite du rectangle
            rectangleCoup.y = rectanglePerso1.y + 60;// gerer la position du coup en fonction des ordonnées (inversé en SDL 0 en haut a gauche)
            if (rectangleCoup.w > 180)
            {
                coup = 6;
            }
            if (strikeSpeed == 1)
            {
                rectangleCoup.w += 2;
            }
            else if (strikeSpeed == 2)
            {
                rectangleCoup.w += 3;
            }
            else
            {
                rectangleCoup.w += 4;
            }

        }

        if ((coup == 6) && (saut == 0))   // retour coup de point bas
        {
            if (rectangleCoup.w <= 0)
            {
                coup = 0;
                side = 1;
                strikeSpeed = 0;
                degat = 0;
            }
            if (strikeSpeed == 1)
            {
                rectangleCoup.w -= 2;
            }
            else if (strikeSpeed == 2)
            {
                rectangleCoup.w -= 3;
            }
            else
            {
                rectangleCoup.w -= 4;
            }

        }

        if ((coupPied == 1) && (saut == 0))   // coup de pied
        {
            rectangleCoup.h = 130;
            rectangleCoup.x = rectanglePerso1.x + rectanglePerso1.w; // permet de commencer le rectangle coup sur la partie droite du rectangle
            rectangleCoup.y = rectanglePerso1.y + 250;// gerer la position du coup en fonction des ordonnées (inversé en SDL 0 en haut a gauche)
            if (rectangleCoup.w > 220)
            {
                coupPied = 2;
            }

            rectangleCoup.w += 4;


        }
        if ((coupPied == 2) && (saut == 0))   // retour coup de pied
        {
            rectangleCoup.w -= 4;
            if (rectangleCoup.w <= 0)
            {
                coupPied = 0;
                side = 1;
                degat = 0;
            }
        }



        if ((toucheScancode[SDL_SCANCODE_D] == 0 && toucheScancode[SDL_SCANCODE_A] == 0 && saut == 0 && snick == 0) || (toucheScancode[SDL_SCANCODE_D] && toucheScancode[SDL_SCANCODE_A] && saut == 0 && snick == 0))
        {
            avancer = 0;
            compteurAvancer = 0;
        }
        destRectDebout.x = rectanglePerso1.x;// permet de mettre le sprite aux coordonnées du rectangle de base car pas forcement même taille entre le rectangle et le sprite
        destRectDebout.y = rectanglePerso1.y;// permet de mettre le sprite aux coordonnées du rectangle de base car pas forcement même taille entre le rectangle et le sprite
        destRectAccroupis.x = rectanglePerso1.x;
        destRectAccroupis.y = rectanglePerso1.y;
        destRectCoupDebout.x = rectanglePerso1.x;
        destRectCoupDebout.y = rectanglePerso1.y;
        destRectCoupAccroupris.x = rectanglePerso1.x;
        destRectCoupAccroupris.y = rectanglePerso1.y;
        destRectwin3.x = rectanglePerso1.x;
        destRectwin3.y = rectanglePerso1.y;


        hitCheck(&coup, &strikeSpeed, &coupPied, &degat, &rectanglePunchingBall, &rectangleCoup, &barreDeVieDroite);// regarder si toucher ou non
        if (barreDeVieDroite.w <= 0 || minuteur <= 0)   // regarde si a gagner
        {
            win(&rectanglePerso1, textureFond, win1, win2, win3, renderer, &destRectDebout, &destRectwin3, &etape, &compteurWin);// affichage si a gagner
        }
        else
        {
            affichage(textureFond, textureSpriteDebout, textureSpriteDebout2, avancer1, avancer2, avancer3, avancer4, avancer5, accroupis, saut1, saut2, saut3, saut4, saut5, saut6, coupDebout1, coupDebout2,
                coupDebout3, coupAccroupis1, coupAccroupis2, coupAccroupis3, coupPied1, coupPied2, coupPied3, deboutBot, renderer, &barreDeVie, &barreDeVieDroite, &barreDeVieRed, &barreDeVieRedDroite
                , &destRectDebout, &destRectAccroupis, &destRectCoupDebout, &destRectCoupAccroupris, &destRectBot1, &rectangleCoup, &snick, &coup, &coupPied, &compteur, &avancer, &compteurAvancer, &compteurSaut, &saut
                , font, timer_text, 900, 70, &color_timer); // affichage si a gagner
        }


        SDL_PollEvent(&touche);// Récupération des actions de l'utilisateur
        switch (touche.type)
        {
        case SDL_KEYUP:
            switch (touche.key.keysym.sym)
            {
            case SDLK_ESCAPE:// Regarde si == touche ESC
                destructionTexture(textureSpriteDebout2, textureSpriteDebout, avancer1, avancer2, avancer3, avancer4, avancer5, accroupis, saut1, saut2, saut3, saut4, saut5, saut6, coupDebout1, coupDebout2, coupDebout3,
                    coupAccroupis1, coupAccroupis2, coupAccroupis3, coupPied1, coupPied2, coupPied3, deboutBot, win1, win2, win3, textureFond, renderer, pwindow);
                jeu = 1;
                *pjouer = 1; // permet d'arreter le jeu
                break;
            case SDLK_g:// Regarde si == touche g
                destructionTexture(textureSpriteDebout2, textureSpriteDebout, avancer1, avancer2, avancer3, avancer4, avancer5, accroupis, saut1, saut2, saut3, saut4, saut5, saut6, coupDebout1, coupDebout2, coupDebout3,
                    coupAccroupis1, coupAccroupis2, coupAccroupis3, coupPied1, coupPied2, coupPied3, deboutBot, win1, win2, win3, textureFond, renderer, pwindow);

                jeu = 1;
                break;

            }
            break;
        }
    }


    SDL_Quit();
}


int main(int argc, char** argv)
{
    int jouer ;
    jouer = 0;
    while (jouer == 0)   // permet de pouvoir recommencer le jeu tant que jouer == 0
    {
        jeu(&jouer);
    }


    return 0;
}



/* modifier pour les touches
liens:
https://wiki.libsdl.org/SDL2/SDL_GetKeyboardState
https://wiki.libsdl.org/SDL2/SDL_Scancode
https://www.remove.bg/fr/upload
*/


/*

difficulté :

    avoir le meme temps pour faire la boucle pour tout le monde

    Recuperer les sprites
    creer plusieuts textures en meme temps


*/

