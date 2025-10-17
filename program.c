#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main ()
{
    bool b_wind_angle= false ;
    bool b_wind_speed= false ;
    bool b_fuel= false ;
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
    bool b_no_return=false;

// faire ca pour chaque variable //
//tu sélectionne par exemple printf et apres tu fais controle+d pour marquer sur plusieurs lignes en meme temps des variable pour gagner du temps //

    int choix; 
    
    printf("1- altitude-pression\n 2- Vitesse vraie\n 3-Vitesse-sol\n 4- Distance franchissable\n 5- Distance de décollage\n 6- Charge alaire\n 7- Taux de montée\n 8- Point de non-retour\n  9- Vitesse de descente\n ");


    do {
    
    printf ("choisir:");
    scanf ("%d",&choix);
    } while ( choix< 1 || choix> 9);


if(choix==1) {
    b_pressure_altitude = true;
    b_pressure = true;
    b_altitude = true;
}

if (choix==2) {
    b_tas=true;
    b_ias=true;
    b_pressure_altitude = true;
    b_pressure = true;
    b_altitude = true;
}

if (choix==3){
    b_ground_speed=true;   
    b_tas=true;
    b_headwind=true;
    b_ias=true;
    b_pressure_altitude = true;
    b_pressure = true;
    b_altitude = true;
}

if (choix==4){
    b_range =true;     
    b_fuel=true;
    b_ground_speed=true;
    b_tas=true;
    b_headwind=true;
    b_wind_angle=true;
    b_wind_speed=true;

    b_ias=true;

    b_pressure_altitude = true;
    b_pressure = true;
    b_altitude = true;
    b_consumption=true;
}

if (choix==5){     
    b_takeoff=true;

    b_pressure_altitude=true;
    b_pressure = true;
    b_altitude = true;

    b_temperature=true;

    b_headwind=true;     
    b_wind_angle=true;
    b_wind_speed=true;

    b_ground_speed=true;     //ground_speed = tas - headwind;
    b_tas=true;

    b_ias=true;

    b_pressure_altitude = true;
    b_pressure = true;
    b_altitude = true;

    b_weight=true;
}

if (choix==6){    
    b_wing_loading=true;
    b_weight=true;
    b_wing_surface=true;
}

if (choix==7){      //rate_of_climb = 700*(1-pressure_altitude/10000)*(1-0.01*fmax(0,temperature-15));
    b_rate_of_climb=true;

    b_pressure_altitude=true;
    b_pressure = true;
    b_altitude = true;
    b_temperature=true;
}

if (choix==8){
    b_no_return=true;     //range/2;
    b_range =true;     
    b_fuel=true;
    b_ground_speed=true;
    b_tas=true;

    b_headwind=true;
    b_wind_angle=true;
    b_wind_speed=true;

    b_ias=true;

    b_pressure_altitude = true;
    b_pressure = true;
    b_altitude = true;
    b_consumption=true;
}

if (choix==9){     //ground_speed*tan(3);
    b_ground_speed=true;
    b_descent_speed=true;
    b_tas=true;
    b_headwind= true;

}

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

    if (b_wind_angle ){ 

        do 
        {
           printf("entrer Direction relative du vent:");
           scanf ("%lf", &wind_angle);
        } while(wind_angle<-3,14159265||wind_angle>3,14159265);

    }
    

    if (b_wind_speed ){ 

        do 
        {
           printf("entrer vitesse vent:");
           scanf ("%d", &wind_speed); 
        }while(wind_speed<0||wind_speed>150); 
    }

    if (b_fuel ){
        
        do 
        {
           printf("entrer carburant disponible:");
           scanf ("%d", &fuel);   
        }while(fuel<20||fuel>350000);
    }


    if (b_consumption ){ 
        do 
        {
           printf("entrer consommation:");
           scanf ("%d", &consumption);
        }while(consumption<10||consumption>15000);
    }  


    if (b_wing_surface ){ 
        do 
        {
           printf("entrer surface alaire:");
           scanf ("%d", &wing_surface);
        }while(wing_surface<5||wing_surface>900);
    } 

    if (b_pressure ){ 
        do
        {
           printf("entrer pression ambiante:");
           scanf ("%d", &pressure);
        }while(pressure<300||pressure>1050);  
    }

    if (b_temperature ){
        do
        { 
           printf("entrer Température extérieure:");
           scanf ("%d", &temperature);
        }while(temperature<-50||temperature>50);
    }    

    if(b_altitude){
        do
        { 
           printf("entrer altitude:");
           scanf ("%d", &altitude);
        }while(altitude<0||altitude>19500);

    }

    if (b_ias ){
        do
        {
           printf("entrer Indicated Air Speede:");
           scanf ("%d", &ias);
        }while(ias<0||ias>500);
    } 

    if (b_weight ){
        do 
        {
           printf("entrer poids total:");
           scanf ("%d", &weight);
        }while(weight<500||weight>600000);
    }
    



    double headwind;
    if (b_headwind){

        headwind = wind_speed*cos(wind_angle);
        printf ("Vent de face=%lf\n", headwind);
    }

    double pressure_altitude;
    if(b_pressure_altitude)
    {
        pressure_altitude = altitude+(1023-pressure)*30;
        printf("Altitude-pression=%lf\n", pressure_altitude);
    }

    double tas;
    if (b_pressure_altitude){

        tas = ias*(1+2*pressure_altitude/1000);
        printf ("Vitesse vraie=%lf\n", tas);
    }

    double ground_speed;
    if (b_ground_speed){
        
        ground_speed = tas - headwind;
        printf ("Vitesse-sol=%lf\n", ground_speed);
    }

    double range;
    if (b_range){
        
        range = fuel*ground_speed*1.852/consumption;
        printf ("Distance franchissable=%lf\n", range);
    }

    double takeoff;
    if (b_takeoff){
        
        takeoff =300*(1+pressure_altitude/1000)*(1-0.01*fmax(0, temperature-15))*(1-headwind/ground_speed)*(weight*weight/1157*1157);
        printf ("Distance de décollage=%lf\n", takeoff);
    }

    double wing_loading;
    if (b_wing_loading){
        
        wing_loading = weight/wing_surface;
        printf("Charge alaire=%lf\n", wing_loading);
    }

    double rate_of_climb;
    if (b_rate_of_climb){
        
        rate_of_climb = 700*(1-pressure_altitude/10000)*(1-0.01*fmax(0,temperature-15));
        printf ("Taux de montée=%lf\n", rate_of_climb);
    }

    double no_return;
    if (b_no_return){
        
        no_return = range/2;
        printf ("Point de non-retour=%lf\n", no_return);
    }

    double descent_speed;
    if (b_descent_speed){
        
        descent_speed = ground_speed*tan(3);
        printf ("Vitesse de descente=%lf\n", descent_speed);
    }
    
    return 0;
}
