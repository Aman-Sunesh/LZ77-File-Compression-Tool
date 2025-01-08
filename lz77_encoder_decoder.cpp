#include <iostream>
#include <fstream>
#include <tuple>
#include <string>

using namespace std;

struct LZ77Tuple {
    size_t offset;
    size_t length;
    char next;
};

ostream& operator<<(ostream& os, const LZ77Tuple& tuple)
{
    os << "(" << tuple.offset << ", " << tuple.length << ", '" << tuple.next << "')";
    return os;
}

// Overload the extraction operator for LZ77Tuple
istream& operator>>(istream& is, LZ77Tuple& tuple)
{
    char ch; // To consume parentheses and commas

    // Expected format: (offset, length, 'nextChar')
    is >> ch; // Read '('
    if (ch != '(') {
        is.setstate(ios::failbit);
        return is;
    }

    is >> tuple.offset; // Read offset

    is >> ch; // Read ','
    if (ch != ',') {
        is.setstate(ios::failbit);
        return is;
    }

    is >> tuple.length; // Read length

    is >> ch; // Read ','
    if (ch != ',') {
        is.setstate(ios::failbit);
        return is;
    }

    is >> ch; // Read '\''
    if (ch != '\'') {
        is.setstate(ios::failbit);
        return is;
    }

    is >> tuple.next; // Read next character

    is >> ch; // Read '\''
    if (ch != '\'') {
        is.setstate(ios::failbit);
        return is;
    }

    is >> ch; // Read ')'
    if (ch != ')') {
        is.setstate(ios::failbit);
        return is;
    }

    return is;
}

void encode(const string& text, size_t windowSize = 13, size_t lookaheadSize = 6);

string decode(size_t windowSize = 13, size_t lookaheadSize = 6);

int main() {
    string text;

    cout << "Enter text to encode: ";
    getline(cin, text);
    cout << endl;

    encode(text);

    string decoded_text = decode();

    cout << "Decoded Text: " << decoded_text;

    return 0;
}

void encode(const string& text, size_t windowSize, size_t lookaheadSize)
{
    ofstream outFile;
    outFile.open("encoded_file.txt");

    if (outFile.fail())
    {
        cerr << "File encoded_file.txt could not be opened";
        exit(1); // End execution of the program
    }

    size_t i = 0;
    size_t n = text.size();

    while (i < n)
    {
        size_t matchLength = 0;
        size_t matchOffset = 0;
        char nextChar = text[i];

        // Define the search window
        size_t searchStart = (i >= windowSize) ? (i - windowSize) : 0;
        size_t searchEnd = i;

        for (size_t j = searchStart; j < searchEnd; j++)
        {
            size_t k = 0;

            while ((k < lookaheadSize) && ((i + k) < n) && (text[j + k] == text[i + k]))
            {
                k++;
            }

            if (k > matchLength)
            {
                matchLength = k;
                matchOffset = i - j;

                if ((i + k) < n)
                {
                    nextChar = text[i + k];
                }
                else {
                    nextChar = '\0';
                }
            }
        }

        if (matchLength > 0)
        {
            LZ77Tuple tuple;
            tuple.offset = matchOffset;
            tuple.length = matchLength;
            tuple.next = nextChar;
            i += matchLength + 1;

            outFile << tuple << "\n";
        }
        else
        {
            LZ77Tuple tuple;
            tuple.offset = 0;
            tuple.length = 0;
            tuple.next = text[i];
            i += 1;

            outFile << tuple << "\n";
        }

    }

}

string decode(size_t windowSize, size_t lookaheadSize)
{
    ifstream inFile;
    inFile.open("encoded_file.txt");

    if (inFile.fail()) {
        cerr << "File could not be opened.\n";
        exit(1); // Terminate the program with an error
    }

    string text = "";
    LZ77Tuple tuple;

    while (inFile >> tuple) {
        size_t matchOffset = tuple.offset;
        size_t matchLength = tuple.length;
        char ch = tuple.next;

        if (matchOffset == 0)
        {
            // If matchOffset is 0, simply append the next character
            text += ch;
        }
        else
        {
            size_t start = text.length() - matchOffset;
            string temp = text;

            // Append matchLength characters from the temporary copy
            for (size_t k = 0; k < matchLength; ++k) {
                if (start + k < temp.length()) {
                    text += temp[start + k];
                }
                else {
                    // If overlapping, append the character just added
                    // This handles cases where the match extends beyond the current text
                    text += text[start + k];
                }
            }
            // Append the next character after copying the match
            text += ch;
        }
    }

    return text;
}
