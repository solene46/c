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

    double headwind=wind_speed*cos(wind_angle);
    double pressure_altitude=altitude+(1023-pressure)*30;
    double tas=ias*(1+2*pressure_altitude/1000);
    double ground_speed=tas - headwind;
    double range=fuel*ground_speed*1.852/consumption;
    double takeoff=	300*(1+pressure_altitude/1000)*(1-0.01*fmax(0, temperature-15))*(1-headwind/ground_speed)*(weight*weight/1157*1157);
    double wing_loading=weight/wing_surface;
    double rate_of_climb=700*(1-pressure_altitude/10000)*(1-0.01*fmax(0,temperature-15));
    double no_return=range/2;
    double descent_speed=ground_speed*tan(3);

    printf ("Vent de face=%lf\n", headwind);
    printf("Altitude-pression=%lf\n", pressure_altitude);
    printf ("Vitesse vraie=%lf\n", tas);
    printf ("Vitesse-sol=%lf\n", ground_speed);
    printf ("Distance franchissable=%lf\n", range);
    printf ("Distance de décollage=%lf\n", takeoff);
    printf ("Charge alaire=%lf\n", wing_loading);
    printf ("Taux de montée=%lf\n", rate_of_climb);
    printf ("Point de non-retour=%lf\n", no_return);
    printf ("Vitesse de descente=%lf\n", descent_speed);

    
    return 0;
}
