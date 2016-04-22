#include <cstdio>
#include <cstring>


inline void print_usage(char* prog_name)
{
  printf("Usage: %s <filename> [<outfile>]\n", prog_name);
}

int main(int arg_count, char* arg_list[])
{
  // Parse arguments
  if (arg_count < 2)
  {
    print_usage(arg_list[0]);
    return 1;
  }

  // Help documentation
  if (strcmp(arg_list[1], "-h") == 0 || strcmp(arg_list[1], "--help") == 0)
  {
    print_usage(arg_list[0]);
    return 0;
  }

  const char* const infile = arg_list[1];
  FILE *fin = fopen(arg_list[1], "r");
  FILE *fout = stdout;

  if (arg_count > 2)
  {
    fout = fopen(arg_list[2], "w");
  }

  char* morse_converter = new char[256*16]();
#define MORSE_PTR(ch) (morse_converter + int(ch) * 16)
#define SET_MORSE(ch, str) strcpy(MORSE_PTR(ch), str);
  SET_MORSE(' ', " ");
  SET_MORSE('\n', "\n");
  SET_MORSE('\t', "\t");
  SET_MORSE('\v', "\v");
  SET_MORSE('\b', "\b");
  SET_MORSE('\a', "\a");
  SET_MORSE('\f', "\f");
  SET_MORSE('\r', "\r");
  SET_MORSE('A', ".-");
  SET_MORSE('B', "-...");
  SET_MORSE('C', "-.-.");
  SET_MORSE('D', "-..");
  SET_MORSE('E', ".");
  SET_MORSE('F', "..-.");
  SET_MORSE('G', "--.");
  SET_MORSE('H', "....");
  SET_MORSE('I', "..");
  SET_MORSE('J', ".---");
  SET_MORSE('K', "-.-");
  SET_MORSE('L', ".-..");
  SET_MORSE('M', "--");
  SET_MORSE('N', "-.");
  SET_MORSE('O', "---");
  SET_MORSE('P', ".--.");
  SET_MORSE('Q', "--.-");
  SET_MORSE('R', ".-.");
  SET_MORSE('S', "...");
  SET_MORSE('T', "-");
  SET_MORSE('U', "..-");
  SET_MORSE('V', "...-");
  SET_MORSE('W', ".--");
  SET_MORSE('X', "-..-");
  SET_MORSE('Y', "-.--");
  SET_MORSE('Z', "--..");
  SET_MORSE('a', ".-");
  SET_MORSE('b', "-...");
  SET_MORSE('c', "-.-.");
  SET_MORSE('d', "-..");
  SET_MORSE('e', ".");
  SET_MORSE('f', "..-.");
  SET_MORSE('g', "--.");
  SET_MORSE('h', "....");
  SET_MORSE('i', "..");
  SET_MORSE('j', ".---");
  SET_MORSE('k', "-.-");
  SET_MORSE('l', ".-..");
  SET_MORSE('m', "--");
  SET_MORSE('n', "-.");
  SET_MORSE('o', "---");
  SET_MORSE('p', ".--.");
  SET_MORSE('q', "--.-");
  SET_MORSE('r', ".-.");
  SET_MORSE('s', "...");
  SET_MORSE('t', "-");
  SET_MORSE('u', "..-");
  SET_MORSE('v', "...-");
  SET_MORSE('w', ".--");
  SET_MORSE('x', "-..-");
  SET_MORSE('y', "-.--");
  SET_MORSE('z', "--..");
  SET_MORSE('0', "-----");
  SET_MORSE('1', ".----");
  SET_MORSE('2', "..---");
  SET_MORSE('3', "...--");
  SET_MORSE('4', "....-");
  SET_MORSE('5', ".....");
  SET_MORSE('6', "-....");
  SET_MORSE('7', "--...");
  SET_MORSE('8', "---..");
  SET_MORSE('9', "----.");
  SET_MORSE('.', ".-.-.-");
  SET_MORSE(',', "--..--");
  SET_MORSE('?', "..--..");
  SET_MORSE('\'', ".----.");
  SET_MORSE('!', "-.-.-----.");
  SET_MORSE('/', "-..-.");
  SET_MORSE('(', "-.--.");
  SET_MORSE(')', "-.--.-");
  SET_MORSE('&', ".-...");
  SET_MORSE(':', "---...");
  SET_MORSE(';', "-.-.-.");
  SET_MORSE('=', "-...-");
  SET_MORSE('+', ".-.-.");
  SET_MORSE('-', "-....-");
  SET_MORSE('_', "..--.-");
  SET_MORSE('"', ".-..-.");
  SET_MORSE('$', "...-..-");
  SET_MORSE('@', ".--.-.");

  const char* const start = "-.-.-";
  const char* const stop = ".-.-.";

  char buffer[2];
  fprintf(fout, "%s", start);
  while(!feof(fin))
  {
    fread(buffer, 1, sizeof(char), fin);
    fprintf(fout, "%s", MORSE_PTR(buffer[0]));
  }
  fprintf(fout, "%s", stop);

  return 0;
}

