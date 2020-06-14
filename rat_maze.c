//Basic rat maze implementing backtracking techniques to find the path to the end of maze (diagonally opposite end)
//5x5 maze rat moves right or down only

#include <stdio.h>
#include <stdbool.h>

int n=5,x=0,y=0,i,j,a;
int step[100];

int maze[5][5] = {{ 1, 0, 0, 0, 1}, 
                  { 1, 1, 1, 1, 0 }, 
                  { 0, 1, 0, 1, 0 }, 
                  { 1, 1, 1, 0, 0 },
                  { 0, 0, 1, 1, 1 } };

int sol[5][5] = { { 0, 0, 0, 0, 0 }, 
                  { 0, 0, 0, 0, 0 }, 
                  { 0, 0, 0, 0, 0 }, 
                  { 0, 0, 0, 0, 0 },
                  { 0, 0, 0, 0, 0 } };

                  

int check_sol();
int is_valid();


int main(){

    printf("\n\nThis is maze --> \n");
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++){
            printf(" %d, ", maze[i][j]); 
        } 
        printf("\n"); 
    }

    check_sol();

    //prints solution maze
    printf("\n\nThis is sol --> \n");
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++){
            printf(" %d, ", sol[i][j]); 
        } 
        printf("\n"); 
    }
    

}

//function to check if position is valid too move.
int is_valid(int i , int j , int maze[5][5] , int sol[5][5]){
    if (i <= n && j <= n && i >= 0 && j >= 0 && maze[i][j] !=0 && sol[i][j] == 0 && sol[i][j] != 2)
        return true;
    else
        return false;
}


//solution checking function
int check_sol(){

    while(x<=n-1 && y<=n-1){

        //at end
        if( is_valid(x , y , maze , sol ) == true && x==4 && y==4){
        sol[x][y] = 1;
        break;
        }

        //at beggining
        else if( is_valid(0 , 0 , maze , sol )== true ){
            sol[x][y] = 1;
            continue;
        }

        //going right
        else if( is_valid(x , y+1 , maze , sol ) == true ){
            sol[x][y+1] = 1;
            a++;
            step[a]= 1;
            y++;
            continue;
        }

        //going down
        else if( is_valid(x+1 , y , maze , sol ) == true ){
            sol[x+1][y] = 1;
            a++;
            step[a]= 0;
            x++;
            continue;
        }

        //if none of the cases are possible; backtracking; marks cell as 2 if it has already been visited and 
        //has been backtracked as it is not a viable position.
        else{
            if(step[a] == 0 ){
                sol[x][y] = 2;
                a--;
                x--;
            }
            if (step[a] == 1 ){
                sol[x][y] = 2;
                a--;
                y--;
            }
        }
        
    }
}

