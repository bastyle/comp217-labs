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

bool isCreamyOrFullFlavour(const Coffee coffee)
{
    return coffee.flavorProfile == "Creamy" || coffee.flavorProfile == "Full Bodied";
}

bool isLightOrMediumAndPriceLess10(const Coffee coffee)
{
    return (coffee.roast == roastType::light || coffee.roast == roastType::medium) && coffee.pricePerKG < 10.0;
}

void printEnum(std::vector<Coffee> stock)
{
    for (Coffee coffee : stock)
    {
        std::cout << static_cast<std::underlying_type<roastType>::type>(coffee.roast) << std::endl;
    }
}

bool isRoast(const Coffee coffee)
{
    return coffee.roast == roastType::dark;
}

double getTotalStockPrice(std::list<Coffee> coffeeSubs, const long subsSize)
{
    if (subsSize == 0)
        return 0;
    std::list<Coffee>::iterator it = coffeeSubs.begin();
    std::advance(it, subsSize-1);
    std::cout << it->pricePerKG << std::endl;
    return (it->pricePerKG+getTotalStockPrice(coffeeSubs,subsSize-1));
}

std::list<Coffee> createSubscription(std::vector<Coffee> stock)
{
    std::list<Coffee> coffeeSubsList;
	std::cout << "Number of Coffees with 'Creamy' or 'Full Bodied' flavor profile: "
        << std::count_if(stock.begin(), stock.end(), isCreamyOrFullFlavour) << "\n";
    std::sort(stock.begin(), stock.end(), [](const Coffee& c1, const Coffee& c2) {
        return c1.roast < c2.roast;
        });
    std::copy_if(stock.begin(), stock.end(), std::back_inserter(coffeeSubsList), isLightOrMediumAndPriceLess10);

	const auto darkRoastIt = std::find_if(stock.begin(), stock.end(), isRoast);
    if (darkRoastIt != stock.end()) {
        coffeeSubsList.push_back(*darkRoastIt);
    }
	
    const double total = getTotalStockPrice(coffeeSubsList, coffeeSubsList.size());
    std::cout << "Total price per KG of Coffees in the subscription: $" << total << "\n";
    return coffeeSubsList;
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
    
    std::vector<Coffee> coffees({
{ "Pacific Pipeline", roastType::medium, "Full Bodied", 8.99 },
{ "Three Sisters", roastType::medium, "Tropical Fruit", 7.99 },
{ "Hola", roastType::light, "Juicy", 11.99 },
{ "Horse Power", roastType::dark, "Creamy", 8.99 },
{ "Decaf", roastType::dark, "Creamy", 5.99 },
{ "Grizzly Claw", roastType::light, "Full Bodied", 9.99 },
        });

    auto coffee_sub = createSubscription(coffees);
    
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
    }
    return 0;
}


