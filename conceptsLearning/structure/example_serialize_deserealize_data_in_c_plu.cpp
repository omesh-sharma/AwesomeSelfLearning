
// Sure, here's an example of serialization and deserialization in C++ using a simple data structure:
// cpp
// Copy code

#include <iostream>
#include <fstream>

// Define a simple data structure
struct Data {
    int value1;
    float value2;
    char value3;
};

// Serialize the data structure to a file
void serialize(const Data& data, const std::string& filename) {
    std::ofstream file(filename, std::ios::binary);
    if (file.is_open()) {
        file.write(reinterpret_cast<const char*>(&data), sizeof(Data));
        file.close();
    } else {
        std::cerr << "Unable to open file for writing." << std::endl;
    }
}

// Deserialize the data structure from a file
Data deserialize(const std::string& filename) {
    Data data;
    std::ifstream file(filename, std::ios::binary);
    if (file.is_open()) {
        file.read(reinterpret_cast<char*>(&data), sizeof(Data));
        file.close();
    } else {
        std::cerr << "Unable to open file for reading." << std::endl;
    }
    return data;
}

int main() {
    // Create a sample data structure
    Data originalData = {42, 3.14f, 'A'};

    // Serialize the data structure to a file
    serialize(originalData, "data.bin");

    // Deserialize the data structure from the file
    Data restoredData = deserialize("data.bin");

    // Print the deserialized data
    std::cout << "Deserialized data: " << std::endl;
    std::cout << "Value 1: " << restoredData.value1 << std::endl;
    std::cout << "Value 2: " << restoredData.value2 << std::endl;
    std::cout << "Value 3: " << restoredData.value3 << std::endl;

    return 0;
}


//In this example, we define a simple Data structure with integer, float, and character fields.
//We then implement serialization and deserialization functions using binary file I/O. The serialize
//function writes the binary representation of the data structure to a file, while the deserialize function
//reads the binary data from the file and constructs a Data object from it. Finally, in the main function, we create a sample Data object, serialize it to a file, deserialize it back into another Data object, and print the deserialized data to verify that it matches the original.