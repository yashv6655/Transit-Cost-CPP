#include <iostream>
#include <vector>

std::vector<double> fares = {2.75, 32.00, 121.00};
std:: vector<std::string> fare_options = {"pay per ride", "7 day unlimited", "30 day unlimited"};

std::vector<double> cost_per_ride(int days, int rides) {
     
        double ppr_price = 2.75;
     
        // days / 7 * 32
     
        double unlimited7_price = (days / 7) * 32;
        if (days % 7 > 0) {
            unlimited7_price += 32.00;
        }
        unlimited7_price /= rides;
        
        double unlimited30_price = 121.00 / rides;
        std::vector<double> ride_prices = {ppr_price, unlimited7_price, unlimited30_price};
        return ride_prices;
}


void get_best_fare(int days, int rides){
    
    std::vector<double> ride_prices = cost_per_ride(days, rides);
    
    double minimum = ride_prices[0];

    int best_index = 0;

    for (int i = 0; i < ride_prices.size(); i++){
        if (ride_prices[i] < minimum) {
            minimum = ride_prices[i];
            best_index = i;
        }
    }

    std::cout << "The cheapest option is " << fare_options[best_index] << "\n";
    std::cout <<"The cost per ride is $" << minimum;



}

int main() {
    
    int days, rides;
    std::cout <<"Welcome to MTA Best Fare\n";


    std::cout <<"How many days will you be using your MetroCard?\n";
    
    std::cin >> days;

    std::cout <<"How many times do you expect to use the subway?\n";
    
    std::cin >> rides;    

    get_best_fare(days, rides);

}
