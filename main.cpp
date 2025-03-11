#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

void printmap(std::vector<std::vector<int>> map, int N){
    
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            if(map[i][j]==0){
                std::cout<<"- ";
            }
            else if(map[i][j]==1){
                std::cout<<"@ ";
            }
            else if(map[i][j]==2 or map[i][j]==4){
                std::cout<<"* ";
            }
            else if(map[i][j]==3){
                std::cout<<"# ";
            }
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}

std::vector<std::vector<int>> makemap(int N, int a, int b){
    std::vector<std::vector<int>> map11;
    
    srand(time(0));
    int start = 0;
    int end = N-1;
    for(int i = 0; i<N; i++){
        std::vector<int> map1;
        for(int j = 0; j<N; j++){
            map1.push_back(0); //rand() % (end - start + 1) + start);
        }
        map11.push_back(map1);
    }
    int i = 0;
    while(i<a){
        int x = rand() % (end - start + 1) + start;
        int y = rand() % (end - start + 1) + start;
        if(map11[x][y] != 1){
            map11[x][y] = 1;
            i++;
        }    
    
    }
    i = 0;
    while(i<b){
        int x = rand() % (end - start + 1) + start;
        int y = rand() % (end - start + 1) + start;
        if(map11[x][y] != 1){
            map11[x][y] = 2;
            i++;
        }    
    
    } /*
    map11[0][2] = 2;
    map11[N-1][2] = 1;
    map11[2][2] = 3;
    map11[2][1] = 3;
    map11[2][3] = 3;
    //map11[1][1] = 3;
    //map11[1][3] = 3;*/
    return map11;
}

std::vector<std::vector<int>> muv(std::vector<std::vector<int>> map, int N){
    std::vector<std::vector<int>> map11 = map;
    
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            
            if(map[i][j]==1){
                char MM;
                std::cout<<i<<' '<<j<<std::endl;
                std::cin>>MM;
                map11[i][j]=0;
                if(MM == 'd'){
                    if(map[i][j+1]!=1){
                        map11[i][j+1]=1;
                    }
                    else{
                        map11[i][j+1]=2;
                    }
                }
                else if(MM == 'a'){
                    if(map[i][j+1]!=2){
                        map11[i][j-1]=1;
                    }
                    else{
                        map11[i][j-1]=2;
                    }
                }
                else if(MM == 'w'){
                    if(map[i-1][j]!=2){
                        map11[i-1][j]=1;
                    }
                    else{
                        map11[i-1][j]=2;
                    }
                }
                else if(MM == 's'){
                    if(map[i+1][j]!=2){
                        map11[i+1][j]=1;
                    }
                    else{
                        map11[i+1][j]=2;
                    }
                
                }
                else{
                    map11[i][j]=1;
                } 
            printmap(map11, N);
                
            }
        }
    }

    return map11;
}

std::vector<std::vector<int>> muv2(std::vector<std::vector<int>> map, int N){
    std::vector<std::vector<int>> map11 = map;
    
    srand(time(0));
    int start = 0;
    int end = 1;
    
    for(int i1 = 0; i1<N; i1++){
        for(int j1 = 0; j1<N; j1++){
            if(map[i1][j1]==1){
                for(int i = 0; i<N; i++){
                    for(int j = 0; j<N; j++){
                        if(map[i][j]==2){
                            map11[i][j]=4;
                            if(abs(i-i1)>=abs(j-j1) and i<i1 and map11[i+1][j]!=3){
                                map11[i+1][j]=2;
                        }
                        else if(abs(i-i1)>=abs(j-j1) and i>i1 and map11[i-1][j]!=3){
                                map11[i-1][j]=2;
                        }
                        else if(abs(i-i1)<=abs(j-j1) and j>j1 and map11[i][j-1]!=3){
                            map11[i][j-1]=2;
                        }
                        else if((i-i1)<=abs(j-j1) and j<j1 and map11[i][j+1]!=3){
                            map11[i][j+1]=2;
                        }
                        else if( map11[i][j+1]==3 and map11[i+1][j]!=3){
                            map11[i+1][j]=2;
                        }
                        else if( map11[i][j-1]==3  and map11[i+1][j]!=3){
                            map11[i+1][j]=2;
                        }
                        else if( map11[i+1][j]==3 and map11[i][j+1]!=3){
                            map11[i][j+1]=2;
                        }
                        else if( map11[i-1][j]==3 and map11[i][j+1]!=3){
                            map11[i][j+1]=2;
                        }
                        } 
                    }
                }    
             printmap(map11, N);
                
            }
        }
    }
    return map11;
}

std::vector<std::vector<int>> muv3(std::vector<std::vector<int>> map, int N){
    std::vector<std::vector<int>> map11 = map;
    
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            
            if(map[i][j]==1){
                char MM;
                std::cout<<i<<' '<<j<<std::endl;
                std::cin>>MM;
                
                if(MM == 'd'){
                        map11[i][j+1]=3;
                }
                else if(MM == 'a'){
                    map11[i][j-1]=3;
                    
                }
                else if(MM == 'w'){
                    
                        map11[i-1][j]=3;
                    
                }
                else if(MM == 's'){
                   
                        map11[i+1][j]=3;
                    
                }
            
             printmap(map11, N);    
            }
        }
    }

    return map11;
}

int main()
{
    int N=10;	
    std::vector<std::vector<int>> map;
    map=makemap(N, 3, 3);
    printmap(map, N);
    for(int i = 0; i<10; i++){
    map = muv(map, N);
    map = muv3(map, N);
    map = muv2(map, N);
    
    }
    return 0;
}
