#include <iostream>
#include <string>

class Book
{
    std::string bookName, bookAuthor, category;
    float bookPrice;

public:
    Book()
        {
            // This is a mistake, bookName is a C++ std::string,
            //     it is neither an array nor a C-string.
            // bookName[] = "xxx";
            bookName = "xxx"; // Hence removed "[]"
            bookAuthor = "yyy";
            bookPrice = 0.0;
            category = "CS";
        }

    std::string checkAuthor()
        {
            return bookAuthor;
        }

    // checkCategory() defined in "Book" class as
    // getter function to private member "category"
    // so that CheckBookInfo(Book[]) can compare if 
    // the "category"  is equal to "CS"
    std::string checkCategory()
        {
            return category;
        }

    void giveDiscount(int);

    void printDetail()
        {
            // This output is mostly difficult to read as it is not
            // properly formatted, however it is left as is, as
            // we are not required to output neatly.
            std::cout << bookName << bookAuthor << bookPrice << category;
        }

    friend Book readValue();
};

// c)
//
// Set new price of book based on "discount" parameter
void Book::giveDiscount(int discount)
{
    if (bookAuthor == "Norbahiah")
    {
        // Reduce price based on discount if written by "Norbahiah"
        bookPrice = bookPrice - bookPrice * discount * 0.01;
    }
    else
    {
        // No discount if written by other authors
        // Give appropriate message if no discount
        std::cout << "No discount for the book titled \"" << bookName << "\"\n";
    }
}

// d)
//
// Receives array of Book
void CheckBookInfo(Book books[], int bookCount = 8)
{
    int csCount = 0;

    for (int i = 0; i < bookCount; ++i)
    {
        // checkCategory() defined in "Book" class as
        // getter function to private member "category"
        if (books[i].checkCategory() == "CS")
        {
            // Print detail info if in CS category
            books[i].printDetail();

            // Count how many book categorized as CS
            csCount++;
        }
    }

    std::cout << "There are " << csCount << " CS books!\n";
}

Book readValue()
{
    Book aBook;
    std::string bookName, bookAuthor, category;
    float bookPrice;
    std::cout << "Please enter the book title " << ": ";
    std::getline(std::cin, aBook.bookName);

    std::cout << "Please enter the name of the author " << ": ";
    std::getline(std::cin, aBook.bookAuthor);

    std::cout << "Please enter the book category " << ": ";
    std::getline(std::cin, aBook.category);

    std::cout << "Please enter the price of the book " << ": ";
    std::cin >> aBook.bookPrice;

    std::cin.ignore();

    return aBook;
}

int main()
{
    Book myBook[8];
    int discount;
    for (int i = 0; i < 8; ++i)
    {
        myBook[i] = readValue();
    }

    std::cout << "Enter percentage amount of discount : ";
    std::cin >> discount;

    for (int i = 0; i < 8; ++i)
    {
        myBook[i].giveDiscount(discount);
    }

    // e)
    //
    // Statement in main() that calls CheckBookInfo(Book[])
    CheckBookInfo(myBook);

    return 0;
}
