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