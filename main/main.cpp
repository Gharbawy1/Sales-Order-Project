#include <iostream>
#include<string>
#include<iomanip>
#include<vector>
#include<Windows.h>
#include"Coustmer.h"
#include"Company.h"
#include"Person.h"
#include"Coustmers.h"
#include"Stock.h"
#include"Order.h"
#include"Transation.h"
void PrintMenu();
int countOrder = 0;
Order AllOrdersList[50];
vector<Order>FoundedOrders;
void PrintFirstMenu();
void Search();
void PrintOrdersMain();
void SearchForOrder();
void  SearchForPay();
void DisplayTransactions();
int main()
{   
    Coustmers CoustmersList(5);
    Stock stock(4);
    Order *order;
    PrintFirstMenu();
    system("cls");
    int choose;
    while (true)
    {
        PrintMenu();
        cout << "          ";
        do
        {
            cout << "          ";
            cout << "\t\t > Enter one Option : ";
            cin >> choose;
            if (choose < 1 || choose>13)
            {
                cout << "          \n\t\t";
                cout << " OOPS !! PLEASE ENTER VALIED OPTION !\n";
                Sleep(1500);
            }

        } while (choose < 1 || choose>13);
        system("cls");
        switch (choose)
        {
        case 1:
            CoustmersList.AddCoustmer();
            break;
        case 2:
            order = new Order(&stock, &CoustmersList);
            order->CreateOrder();
            AllOrdersList[countOrder++] = *order;
            break;
        case 3:
            CoustmersList.EditCoustmer();
            break;
        case 4 :
            CoustmersList.DeleteCoustmer();
            break;
        case 5 :
            stock.AddProductToStock();
            break;
        case 6:
            stock.DeleteProduct();
            break;
        case 7:
            stock.UpdateStockProduct();
            break;
        case 8:
            // Print All Order Is Done
            for (int i = 0; i < countOrder; i++) {
                cout << AllOrdersList[i] << "\n";
            }
            break;
        case 9:
            CoustmersList.PrintIdForSpiceficCoustmer();
            cout << "  > DO YOU WANT TO DISPLAY DETAILS (Y/N) : "; char n; cin >> n;
            if (n == 'y') {
                Search();
                PrintOrdersMain();
            }
            break;  
        case 10:
            stock.PrintAllProducts();
            break;
        case 11:
            SearchForOrder();// in main function to search and if it found go to edit fun in order class
            break;
        case 12:
            SearchForPay();
            break;
        case 13:
            DisplayTransactions();
            break;
        }
    }
}


// for Displaying 
void Search() {
    //memset(&FoundedOrders, NULL, FoundedOrders.size());
    cout << ">> ENTER ID WHICH ORDER YOU WNAT TO DISPLAY : "; int id; cin >> id;
    for (int i = 0; i < countOrder; i++) {
        if (AllOrdersList[i].GetOrderId() == id) {
            
            FoundedOrders.push_back(AllOrdersList[i]);
            cout << " >> DISPLAY MORE ? (Y/N)"; char n; cin >> n;
            if (n == 'y') {
                cout << "> ENTER ANOTHER ID PLEASE : ";
                cin >> id;
            }
            else {
                break;
            }
        }
    }
}
void PrintOrdersMain() {
    for (int i = 0; i < FoundedOrders.size(); i++) {
        cout << FoundedOrders[i];
    }
}

// search for find the order and make the payment 
void SearchForPay() {
    Transation Transaction;
    cout << "> PLEASE ENTER THE ORDER ID : "; int id; cin >> id;
    bool IsOrderFound = false;
    for (int i = 0; i < countOrder; i++) {
        if (AllOrdersList[i].GetOrderId() == id) {
            cout << "> FOUNDED SUCCESSFULLY \n\n";
            Transaction.SetTrasicationData();
            AllOrdersList[i].AddTransaction(Transaction);
            // set the payment
        }
    }
}
// search for displaying transactions
void DisplayTransactions() {
    cout << "> PLEASE ENTER THE ORDER ID : "; int id; cin >> id;
    bool IsOrderFound = false;
    for (int i = 0; i < countOrder; i++) {
        if (AllOrdersList[i].GetOrderId() == id) {
            cout << "> FOUNDED SUCCESSFULLY \n\n";
            AllOrdersList[i].ViewTransactons();
            // set the payment
        }
    }

}
// for editing 
void SearchForOrder() {
    cout << "> PLEASE ENTER THE ORDER ID : "; int id; cin >> id;
    bool IsOrderFound = false;
    for (int i = 0; i < countOrder; i++) {
        if (AllOrdersList[i].GetOrderId() == id) {
            cout << "> FOUNDED SUCCESSFULLY \n\n";
            AllOrdersList[i].EditOrder();
        }
    }
}


void PrintMenu()
{
    cout << "\n ====  Coustmer Service  ====   \t\t ====  Stock Mangment  ===  \t====  Transaction Mangment  ===\n";
    cout << "     [1] Add Coustmer .\t\t     |\t     [5] Add Product .\t             [12] Add Transaction .\n";
    cout << "     [2] Create An Order .\t     |\t     [6] Delete Product .\t     [13] View Transaction\n";
    cout << "     [3] Modify Coustmer .\t     |\t     [7] Modify Product .          \n";
    cout << "     [4] Delete Coustmer . \n     [8] Print All Orders In System .\n     [9] Print Your Orders .\n     [10] Print All Products in Stock .\n";
    cout << "     [11] Update Order . \n";
}
void PrintFirstMenu() {
    int n;
    cout << "                     ---------------------------------------------------------------------\n";
    cout << setw(90) << "|    [1] Go To System                                  [0] Exit     |" << endl;
    cout << "                     ---------------------------------------------------------------------\n";
    do {
        cout << "\n Enter one Opetion : ";
        cin >> n;
        if (n != 1)
        {
            if (n != 0)
            {
                cout << "PLEASE ENTER VALIED OPTION !";
                Sleep(1500);
            }
        }
    } while (n != 1 && n != 0);

       
}
