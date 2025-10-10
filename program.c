#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main ()
{
    bool b_wind_angle= false ;
    bool b_wind_speed= false ;
    bool b_fuel_= false ;
    bool b_consumption = false ;
    bool b_wing_surface = false ;
    bool b_pressure = false ;
    bool b_temperature = false ;
    bool b_altitude = false ;
    bool b_ias = false ;
    bool b_weight = false ;
    bool b_headwind = false ;
    bool b_pressure_altitude = false ;
    bool b_tas = false ;
    bool b_ground_speed = false ;
    bool b_range = false ;
    bool b_takeoff =  false ;
    bool b_wing_loading = false ;
    bool b_rate_of_climb = false ;
    bool b_return = false ;
    bool b_descent_speed = false;

// faire ca pour chaque variable //
//tu sélectionne par exemple printf et apres tu fais controle+d pour marquer sur plusieurs lignes en meme temps des variable pour gagner du temps //

    int choix; 
    
    printf("1- altitude-pression\n 2- Vitesse vraie\n 3-Vitesse-sol\n 4- Distance franchissable\n 5- Distance de décollage\n 6- Charge alaire\n 7- Taux de montée\n 8- Point de non-retour\n  9- Vitesse de descente\n ");
    printf ("choisir:");
    scanf ("%d",&choix);

if(choix==1) {
    b_pressure_altitude = true;
    b_pressure = true;
    b_altitude = true;
}

if (choix==2)

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

    if(b_altitude){
        printf("entrer altitude:");
        scanf ("%d", &altitude);    

    }

    printf("entrer Indicated Air Speede:");
    scanf ("%d", &ias); 

    printf("entrer poids total:");
    scanf ("%d", &weight); 

    double headwind;
    
    headwind = wind_speed*cos(wind_angle);
    double pressure_altitude;
    
    if(b_pressure_altitude)
    {
        pressure_altitude = altitude+(1023-pressure)*30;
        printf("Altitude-pression=%lf\n", pressure_altitude);
    }
        double tas;
    
    tas = ias*(1+2*pressure_altitude/1000);
    double ground_speed;
    
    ground_speed = tas - headwind;
    double range;
    
    range = fuel*ground_speed*1.852/consumption;
    double takeoff;
    
    takeoff = 	300*(1+pressure_altitude/1000)*(1-0.01*fmax(0, temperature-15))*(1-headwind/ground_speed)*(weight*weight/1157*1157);
    double wing_loading;
    
    wing_loading = weight/wing_surface;
    double rate_of_climb;
    
    rate_of_climb = 700*(1-pressure_altitude/10000)*(1-0.01*fmax(0,temperature-15));
    double no_return;
    
    no_return = range/2;
    double descent_speed;
    
    descent_speed = ground_speed*tan(3);

    printf ("Vent de face=%lf\n", headwind);
    
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
