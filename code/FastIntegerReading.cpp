#include <iostream>   
int main()
{
    int lc = 0;
    int item = 0;
    char buf[2048];
    do
    {
        std::cin.read(buf, sizeof(buf));
        int k = std::cin.gcount();
        for (int i = 0; i < k; ++i)
        {
            switch (buf[i])
            {
                case '\r':
                    break;
                case '\n':
                    item = 0; lc++;
                    break;
                case ' ':
                    item = 0;
                    break;
                case '0': case '1': case '2': case '3':
                case '4': case '5': case '6': case '7':
                case '8': case '9':
                    item = 10*item + buf[i] - '0';
                    break;
                default:
                    std::cerr << "Bad format\n";
            }    
        }
    } while (std::cin);
}
