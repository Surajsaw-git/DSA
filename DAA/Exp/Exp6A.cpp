#include <iostream>
#include <algorithm>

using namespace std;

struct Item
{
    int id;
    float profit;
    float weight;
    float ratio;
};

bool compare(Item a, Item b)
{
    return a.ratio > b.ratio;
}

int main()
{
    int n;
    float capacity;

    cout << "Enter number of items: ";
    cin >> n;

    Item items[n];

    cout << "Enter profit and weight of each item:\n";

    for (int i = 0; i < n; i++)
    {
        items[i].id = i + 1;

        cin >> items[i].profit;
        cin >> items[i].weight;

        items[i].ratio =
            items[i].profit / items[i].weight;
    }

    cout << "Enter truck capacity: ";
    cin >> capacity;

    // Sort according to profit/weight ratio
    sort(items, items + n, compare);

    float totalProfit = 0;

    cout << "\nSelected Items:\n";

    for (int i = 0; i < n; i++)
    {
        if (capacity == 0)
            break;

        // Take complete item
        if (items[i].weight <= capacity)
        {
            capacity -= items[i].weight;

            totalProfit += items[i].profit;

            cout << "Item " << items[i].id
                 << " -> 100% selected\n";
        }

        // Take fraction
        else
        {
            float fraction =
                capacity / items[i].weight;

            totalProfit +=
                items[i].profit * fraction;

            cout << "Item " << items[i].id
                 << " -> "
                 << fraction * 100
                 << "% selected\n";

            capacity = 0;
        }
    }

    cout << "\nMaximum Profit = "
         << totalProfit << endl;

    return 0;
}