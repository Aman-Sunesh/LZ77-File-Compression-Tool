# LZ77 File Compression Tool

## Overview
The **LZ77 File Compression Tool** is a C++ application that implements the LZ77 compression algorithm to compress and decompress files. This tool provides a command-line interface allowing users to efficiently reduce file sizes and restore them to their original state. It is an excellent project for understanding fundamental compression techniques and enhancing your C++ programming skills.

## Prerequisites
Before you can run this application, ensure you have the following installed:
- C++ Compiler (e.g., `g++`, `Clang`)
- C++11 or higher standard support

## Installation

### C++ Compiler Installation
If you don't have a C++ compiler installed, you can install `g++` using the following commands:

- **For Ubuntu/Debian-based systems:**
  ```bash
  sudo apt update
  sudo apt install build-essential

- **For macOS (using Homebrew):**
    ```bash
    brew install gcc
    ```

- **For Windows:**
    - Install [MinGW](http://www.mingw.org/) or use [Visual Studio](https://visualstudio.microsoft.com/) with C++ development tools.

### Clone the Repository
Clone the repository to your local machine using Git:
```bash
git clone https://github.com/yourusername/LZ77-File-Compression-Tool.git
cd LZ77-File-Compression-Tool
```

## Compilation
Compile the C++ source code using your preferred compiler. For example, using g++:
```bash
g++ -std=c++11 -o LZ77_Compression_Tool lz77_encoder_decoder.cpp
```
Ensure that all source files (main.cpp and any other necessary files) are in the project directory.

## Usage
After compiling, you can use the tool via the command line.

### Encoding (Compression)
To compress a file, run the executable and provide the text to encode when prompted:
```bash
./LZ77_Compression_Tool
```

Example:
```bash
Enter text to encode: THISISATESTTEXT
```
The tool will create an encoded_file.txt containing the compressed tuples.


### Decoding (Decompression)
The tool automatically decodes the compressed file and displays the decoded text:

```bash
Decoded Text: THISISATESTTEXT
```

## Functionality

### Compression (Encode)
- **Input**: A string of text entered by the user.
- **Process**:
  - Implements the LZ77 algorithm using a sliding window and lookahead buffer.
  - Finds matching substrings within the window and encodes them as tuples `(offset, length, next character)`.
- **Output**: Writes the encoded tuples to `encoded_file.txt`.

### Decompression (Decode)
- **Input**: The `encoded_file.txt` containing LZ77 tuples.
- **Process**:
  - Reads the tuples and reconstructs the original text by referencing previous substrings based on the offset and length.
- **Output**: Displays the decoded text to verify the integrity of the compression-decompression process.

## Important Notes
- **Window Size and Lookahead Buffer**: The default window size is set to 13, and the lookahead buffer size is set to 6. These can be adjusted in the `encode` and `decode` functions to optimize performance based on the input data.
- **File Handling**: The tool writes the compressed data to `encoded_file.txt` in the same directory as the executable. Ensure you have write permissions for this directory.
- **Character Encoding**: The tool handles standard ASCII characters. Special characters or different encodings may require additional handling.

## Troubleshooting

### Compilation Errors
- **Issue**: Errors during compilation related to missing headers or syntax.
- **Solution**: Ensure you are using a C++11-compatible compiler. Verify that all source files are present and correctly named.

### File Not Found
- **Issue**: `encoded_file.txt` cannot be opened or is missing.
- **Solution**: Ensure that the file exists in the directory and that the program has the necessary permissions to read/write files.

### Decoded Text Mismatch
- **Issue**: The decoded text does not match the original input.
- **Solution**: Check for any modifications in the encoding or decoding logic. Ensure that the entire compression-decompression cycle is correctly implemented without data loss.

### Runtime Errors
- **Issue**: Unexpected termination or crashes during execution.
- **Solution**: Use debugging tools or add additional print statements to trace the program's execution. Ensure that all edge cases are handled, such as end-of-file conditions and empty inputs.

## Contributing
Contributions are welcome! Please fork the repository and submit a pull request with your improvements or additional features. Whether it's enhancing the algorithm, optimizing performance, or adding new functionalities, your contributions are valuable.

## Acknowledgments
- [LZ77 Compression Algorithm](https://en.wikipedia.org/wiki/LZ77_and_LZ78)
- [C++ Documentation](https://cplusplus.com/doc/tutorial/)
