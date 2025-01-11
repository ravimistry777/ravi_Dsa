#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 

void clearScreen() {
    system("clear");
}

int main() {
    int position = 0;
    int max_position = 50; 
    int speed = 1;          
    
    while (1) {
        clearScreen();  

        for (int i = 0; i < position; i++) {
            printf(" ");
        }

        printf("->\n");

        position += speed;
        
        if (position >= max_position || position <= 0) {
            speed = -speed;  
        }

        usleep(100000);  
    }

    return 0;
}
