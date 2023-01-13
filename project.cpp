#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <unistd.h> //for linux
// #include<windows.h> //windows

using namespace std;

string u_name = "admin", u_password = "admin", confirm_password = "";
int p_w = 0, p_h = 0, p_d = 0; // pallet variables

bool login()
{
    string name, password;
    int counter = 0;
    cout << " Enter the username:";
    cin >> name;
    cout << "Enter the password:";
    cin >> password;
    if (u_name == name && u_password == password)
    {
        return true;
    }
    else
    {
        cout << "Wrong Creditionals";
        cout << endl;
        return false;
    }
    return false;
}

void takeSignUp()
{
    cout << "Enter your username:";
    cin >> u_name;
    cout << "Enter your password:";
    cin >> u_password;
    cout << "Enter confirm password:";
    cin >> confirm_password;
}
void signup()
{
    takeSignUp();
    int counter = 0;
    if (u_password != confirm_password)
    {
        cout << "Password and Confirm Password doesn't match!\n";
        cout << "Retry" << endl;
        while (true)
        {
            if (counter == 3)
            {
                break;
            }
            if (counter == 1)
            {
                cout << "You have left one chance to type write password otherwise you will have to wait run the program again\n";
            }
            takeSignUp();
            counter++;
        }
    }
    else
    {
        cout << "Registered Successfully" << endl;
    }
}

struct Product
{
    int width, height, depth, weight;
};

vector<Product> product;
class PalletOptimation : public Product
{

public:
    PalletOptimation()
    {
        width = height = depth = weight = 0;
    }

    // Function to Check Pallet Fits or Not
    bool fits(const Product &product, int width, int height, int depth)
    {
        return product.width <= width && product.height <= height && product.depth <= depth;
    }

    //  Function that finds the optimal arrangement of products on a pallet, based on their dimensions and weight, to minimize the amount of wasted space.

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

    // Function to calculate the total weight of pallete products

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

    // Function to add products on the pallet
    void addProduct(vector<Product> &products, int width, int height, int depth, int weight)
    {
        Product newProduct = {width, height, depth, weight};
        products.push_back(newProduct);
    }

    // Function to remove a product on the pallet
    void removeProduct(vector<Product> &products, int index)
    {
        products.erase(products.begin() + index);
    }

    // Function to "rotate_product" that takes a product as a parameter and rotates it by 90 degrees (swaps the width and depth values)

    void rotate_product(Product &product)
    {
        int temp = product.width;
        product.width = product.depth;
        product.depth = temp;
    }

    // Function to sort ascending order using stl function and lambda function to sort the product by their weight

    void sort_by_weight(vector<Product> &products)
    {
        sort(products.begin(), products.end(), [](const Product &p1, const Product &p2)
             { return p1.weight < p2.weight; });
    }

    // Function to display the pallet
    void display_pallet(vector<Product> products, int pallet_width, int pallet_height, int pallet_depth)
    {
        cout << "Pallet with dimensions " << pallet_width << "x" << pallet_height << "x" << pallet_depth << endl;
        cout << "Products on the pallet:" << endl;
        for (const auto &product : products)
        {
            cout << "Product with dimensions " << product.width << "x" << product.height << "x" << product.depth << " and weight " << product.weight << endl;
        }
    }
};

int main()
{
    PalletOptimation project;
    cout << "--------------------------------------------------------------------"
         << endl;
    cout << "\t\t\t"
         << "Pallet Optimization\n"
         << "---------------------------------------------------------------------"
         << "\n\n";
    unsigned int microsecond = 1000000; // for linux
    usleep(2 * microsecond);            // sleeps for 3 second //for unix or linux
    //  Sleep(milliseconds); windows
    system("clear"); // for linux
    // system("cls")

    while (true)
    {
        cout << "⚠ To Use This Application You mush have to sign in" << endl;
        cout << endl
             << "Press 1 to Sign In" << endl
             << "Press 2 to Sign Up" << endl
             << "Press 3 to Exit" << endl;
        int option;
        cout << "Enter your choice:";
        cin >> option;
        if (option == 3)
        {
            break;
        }
        switch (option)
        {
        case 1:

            if (login() == 1)
            {
                system("clear"); // for linux
                // system("cls"); //for windows
                cout << "\n\t\t\t"
                     << "Welcome to my Project Pallet Optimization made by Raja Hasnat"
                     << "\n\n";
                int ch;
                while (true)
                {
                    cout << "Press 1 to Add Products in Pallet" << endl;
                    cout << "Press 2 to Remove Products in Pallet" << endl;
                    cout << "Press 3 to For Pallet Details" << endl;
                    cout << "Press 4 to Sort Products in Pallet" << endl;
                    cout << "Press 5 to Optimize Pallet(Vip*) and also show remaing space in Pallet" << endl;
                    cout << "Press 6 to rotate specific product by 90° degree" << endl;
                    cout << "Press 7 to display the pallet" << endl;
                    cout << "Press 8 to Back" << endl;
                    cout << "\nEnter your choice: ";
                    cin >> ch;
                    if (ch == 8)
                    {
                        break;
                    }
                    switch (ch)
                    {
                    case 1:
                        int w1, h, d, w2;
                        cout << "\n\nAdd Product on Pallet" << endl;
                        cout << "Enter the Product width:";
                        cin >> w1;
                        cout << "Enter the Product height:";
                        cin >> h;
                        cout << "Enter the Product depth:";
                        cin >> d;
                        cout << "Enter the Product weight:";
                        cin >> w2;
                        project.addProduct(product, w1, h, d, w2);
                        break;
                    case 2:
                        int no;
                        cout << "\n\nEnter the Product number of product which you want to remove:";
                        cin >> no;
                        project.removeProduct(product, no);
                        break;
                    case 3:
                        cout << "Pallet Optimaztion\n\n\n";
                        cout << "Enter the Pallet Width:";
                        cin >> p_w;
                        cout << "Enter the Pallet Height:";
                        cin >> p_h;
                        cout << "Enter the Pallet Depth:";
                        cin >> p_d;
                        break;
                    case 4:
                        cout << "\n\nProduct has been Sorted in Ascending Order with their Weights\n";
                        project.sort_by_weight(product);
                        cout << "Hint: Display Pallet to See the Sorting of Products\n";
                        break;
                    case 5:
                        if (p_w == 0 || p_h == 0 || p_d == 0)
                        {
                            cout << "Can't Pallet Optimzation without pallet information" << endl;
                        }
                        else
                        {
                            project.pallet_optimization(product, p_w, p_h, p_d);
                        }
                        break;
                    case 6:
                        int n;
                        cout << "Enter the Product number to rotate  product by 90° degree";
                        cin >> n;
                        n = n - 1;
                        project.rotate_product(product[n]);
                        break;
                    case 7:
                        if (p_w == 0 || p_h == 0 || p_d == 0)
                        {
                            cout << "Can't display without pallet information" << endl;
                        }
                        else
                        {
                            project.display_pallet(product, p_w, p_h, p_d);
                        }
                        break;
                    case 8:
                        break;
                    default:
                        cout << "Invalid option" << endl;
                        break;
                    }
                }
            }
            break;
        case 2:
            signup();
            break;
        case 3:
            break;
        default:
            cout << "Invalid option" << endl;
            break;
        }
    }

    return 0;
}