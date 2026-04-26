#include <gtest/gtest.h>
#include <fstream>
#include <string>

void print(const std::string& text, std::ostream& out) {
    out << text;
}

TEST(Print, InFileStream)
{
    std::string filepath = "file.txt";
    std::string text = "hello";
    std::ofstream out(filepath);

    print(text, out);
    out.close();

    std::string result;
    std::ifstream in(filepath);
    in >> result;

    EXPECT_EQ(result, text);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
