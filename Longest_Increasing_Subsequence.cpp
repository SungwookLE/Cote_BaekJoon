#include <iostream>
#include <vector>

class solver_LIS{ // Longest Increasing Subsequence
    public:
        solver_LIS(int size){
            N=size;
            array.resize(N,0);
            DP.resize(N,0);
            for (int i =0 ; i < N ; ++i){
                std::cin >> array[i] ;
            }
        }

        void debugger_DP(){
            std::cout << "DEBUG(array): \n";
            for(auto element : DP)
                std::cout << element << " ";
            std::cout << std::endl;
        }

        void solver(){

            int final_max =0;
            for (int i = 0 ; i < N ; ++i){
                int temp_max=0;
                for (int j =0 ; j < i ; ++j){
                    if (array[i] > array[j]){
                        if (DP[j] > temp_max)
                            temp_max = DP[j];
                    }
                }
                DP[i] = temp_max+1;
                final_max = std::max(final_max, DP[i]);
            }
            answer = final_max;
        }

        int answer=0;

    private:
        int N;
        std::vector<int> array;
        std::vector<int> DP;

};

int main(){
    int N;
    std::cin >> N;

    solver_LIS solver(N);
    solver.solver();
    solver.debugger_DP();
    
    std::cout<<"LONGEST INCREASING SUBSEQUENCE(n): \n" <<solver.answer<< std::endl;




    return 0;
}