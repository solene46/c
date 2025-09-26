#include <stdio.h>
#include <math.h>

int main ()
{
    double wind_angle;
    int wind_speed;
    int fuel;
    int consumption;
    int wing_surface;
    int pressure;
    int temperature;
    int altitude;
    int ias;
    int weight;

    printf("entrer Direction relative du vent:");
    scanf ("%lf", &wind_angle);

    printf("entrer vitesse vent:");
    scanf ("%d", &wind_speed);    

    printf("entrer carburant disponible:");
    scanf ("%d", &fuel);   
    
    printf("entrer consommation:");
    scanf ("%d", &consumption);  

    printf("entrer surface alaire:");
    scanf ("%d", &wing_surface);  

    printf("entrer pression ambiante:");
    scanf ("%d", &pressure);  
    
    printf("entrer Température extérieure:");
    scanf ("%d", &temperature);    

    printf("entrer altitude:");
    scanf ("%d", &altitude);    

    printf("entrer Indicated Air Speede:");
    scanf ("%d", &ias); 

    printf("entrer poids total:");
    scanf ("%d", &weight); 

    
    return 0;
}
