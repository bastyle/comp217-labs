// Lab6BB.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <algorithm>
#include <iostream>
#include <list>
#include <numeric>
#include <vector>

enum class roastType
{
    light, medium, dark
};

struct Coffee
{
    std::string name;
    roastType roast;
    std::string flavorProfile;
    double pricePerKG{};
};
std::list<std::string> listOfSpecificFlavors ={ "Creamy", "Full Bodied"};

template<typename Func>
bool isIt(std::string flavour, Func func)
{
    return func(flavour);
}

template<typename Func>
bool isCondition(Coffee coffee, Func func)
{
    return func(coffee);
}

bool isFlavour(Coffee coffee)
{
    return coffee.flavorProfile == "Creamy" || coffee.flavorProfile == "Full Bodied";
}

std::list<Coffee> createSubscription3(std::vector<Coffee> stock)
{
    std::list<Coffee> listCoffees;
	/*std::cout << "Number of Coffees with 'Creamy' or 'Full Bodied' flavor profile: "
        << std::count_if(stock.begin(), stock.end(), [](const Coffee& coffee) {
        return coffee.flavorProfile == "Creamy" || coffee.flavorProfile == "Full Bodied";
            }) << "\n";*/
    std::cout << "Number of Coffees with 'Creamy' or 'Full Bodied' flavor profile: "
        << std::count_if(stock.begin(), stock.end(), isFlavour) << "\n";
    return listCoffees;
}



std::list<Coffee> createSubscription2 (std::vector<Coffee> coffeeStack)
{

    std::list<Coffee> listCoffees;
    int specificFlavorCount = 0;
    /*for (auto coffe : coffeeStack) {
        bool found = (std::find(listOfSpecificFlavors.begin(), listOfSpecificFlavors.end(), coffe.flavorProfile) != listOfSpecificFlavors.end());
        specificFlavorCount+=found?1:0;       
    }*/
    //bool found = (std::find(coffeeStack.begin(), coffeeStack.end(), "Creamy",) != coffeeStack.end());
    //int64_t counter = std::count(coffeeStack.begin(), coffeeStack.end(), "Creamy");
    int64_t counter = std::count(listOfSpecificFlavors.begin(), listOfSpecificFlavors.end(), "Creamy");

    std::cout << "There are "<< counter << " coffees with these flavors: !\n";
    return listCoffees;
}

/*std::list<Coffee> createSubscription(const std::vector<Coffee>& stock)
{
    // Step 1: Print the number of coffees with "Creamy" or "Full Bodied" flavor profile
    std::cout << "Number of Coffees with 'Creamy' or 'Full Bodied' flavor profile: "
        << std::count_if(stock.begin(), stock.end(), [](const Coffee& coffee) {
        return coffee.flavorProfile == "Creamy" || coffee.flavorProfile == "Full Bodied";
            }) << "\n";

    // Step 2: Sort the stock based on roastType (in the order of light, medium, dark)
    std::sort(stock.begin(), stock.end(), [](const Coffee& c1, const Coffee& c2) {
        return c1.roast < c2.roast;
        });

    // Step 3: Create a list of Coffees that contains only light and medium roasts
    // with price less than $10 per KG
    std::list<Coffee> subscription;
    std::copy_if(stock.begin(), stock.end(), std::back_inserter(subscription), [](const Coffee& coffee) {
        return (coffee.roast == roastType::light || coffee.roast == roastType::medium) && coffee.pricePerKG < 10.0;
        });

    // Step 4: Add the first dark roast coffee to the subscription
    auto darkRoastIt = std::find_if(stock.begin(), stock.end(), [](const Coffee& coffee) {
        return coffee.roast == roastType::dark;
        });
    if (darkRoastIt != stock.end()) {
        subscription.push_back(*darkRoastIt);
    }

    // Step 5: Tally up the total price per KG of all the Coffees in the subscription and print it to the screen
    double total = std::accumulate(subscription.begin(), subscription.end(), 0.0, [](double sum, const Coffee& coffee) {
        return sum + coffee.pricePerKG;
        });
    std::cout << "Total price per KG of Coffees in the subscription: $" << total << "\n";

    return subscription;
}
*/

int main()
{
    std::cout << "Hello World!\n";
    std::vector<Coffee> coffees({
{ "Pacific Pipeline", roastType::medium, "Full Bodied", 8.99 },
{ "Three Sisters", roastType::medium, "Tropical Fruit", 7.99 },
{ "Hola", roastType::light, "Juicy", 11.99 },
{ "Horse Power", roastType::dark, "Creamy", 8.99 },
{ "Decaf", roastType::dark, "Creamy", 5.99 },
{ "Grizzly Claw", roastType::light, "Full Bodied", 9.99 },
        });

    createSubscription3(coffees);

	/*auto coffee_sub = createSubscription(coffees);
    

	void(*roastFunc[3])() = {
    []() { std::cout << "Light"; },
    []() { std::cout << "Medium"; },
    []() { std::cout << "Dark"; }
    };
    std::cout << "\nCoffee Subscription" << std::endl;
    for (auto& x : coffee_sub) {
	    std::cout << x.name << " | ";
        roastFunc[(int)x.roast]();
        std::cout << " | " << x.flavorProfile << " | " << x.pricePerKG << std::endl;
    }*/
    return 0;
}


