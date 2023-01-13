#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;
struct Product
{
    int width, height, depth, weight;
};

bool fits(const Product &product, int width, int height, int depth)
{
    return product.width <= width && product.height <= height && product.depth <= depth;
}

void pallet_optimization(vector<Product> products, int pallet_width, int pallet_height, int pallet_depth)
{
    int remaining_width = pallet_width, remaining_height = pallet_height, remaining_depth = pallet_depth;
    for (const auto &product : products)
    {
        if (fits(product, remaining_width, remaining_height, remaining_depth))
        {
            cout << "Product with dimensions " << product.width << "x" << product.height << "x" << product.depth << " and weight " << product.weight << " fits." << endl;
            remaining_width -= product.width;
            remaining_height -= product.height;
            remaining_depth -= product.depth;
        }
        else
        {
            cout << "Product with dimensions " << product.width << "x" << product.height << "x" << product.depth << " and weight " << product.weight << " does not fit." << endl;
        }
    }
    cout << "Remaining space: " << remaining_width << "x" << remaining_height << "x" << remaining_depth << endl;
}

int totalWeight(vector<Product> products, int pallet_width, int pallet_height, int pallet_depth)
{
    int weight_on_pallet = 0;
    int remaining_width = pallet_width, remaining_height = pallet_height, remaining_depth = pallet_depth;
    for (const auto &product : products)
    {
        if (fits(product, remaining_width, remaining_height, remaining_depth))
        {
            weight_on_pallet += product.weight;
            remaining_width -= product.width;
            remaining_height -= product.height;
            remaining_depth -= product.depth;
        }
    }
    return weight_on_pallet;
}
void addProduct(vector<Product> &products, int width, int height, int depth, int weight)
{
    Product newProduct = {width, height, depth, weight};
    products.push_back(newProduct);
}

// Function to remove a product from the vector of products
void removeProduct(vector<Product> &products, int index)
{
    products.erase(products.begin() + index);
}
/* Add a new function called "rotate_product" that takes a product as a parameter and rotates it by 90 degrees (swaps the width and depth values).*/

void rotate_product(Product &product)
{
    int temp = product.width;
    product.width = product.depth;
    product.depth = temp;
}
void sort_by_weight(vector<Product> &products)
{
    sort(products.begin(), products.end(), [](const Product &p1, const Product &p2)
         { return p1.weight < p2.weight; });
}
void display_pallet(std::vector<Product> products, int pallet_width, int pallet_height, int pallet_depth)
{
    std::cout << "Pallet with dimensions " << pallet_width << "x" << pallet_height << "x" << pallet_depth << std::endl;
    std::cout << "Products on the pallet:" << std::endl;
    for (const auto &product : products)
    {
        std::cout << "Product with dimensions " << product.width << "x" << product.height << "x" << product.depth << " and weight " << product.weight << std::endl;
    }
}
int main()
{
    vector<Product> products = {{20, 30, 40}, {30, 30, 30}, {10, 10, 10, 20}};
    int pallet_width = 100, pallet_height = 100, pallet_depth = 100;
    cout << totalWeight(products, pallet_width, pallet_height, pallet_depth);
    rotate_product(products[0]);
    sort_by_weight(products);
    pallet_optimization(products, pallet_width, pallet_height, pallet_depth);

    return 0;
}