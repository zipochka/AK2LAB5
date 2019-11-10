#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <getopt.h>

int main (int argc, char **argv)
{
  int c, sum = 0;
  int bear = 0, wolves = 0, rabbits = 0;
  char *rabbit_num = 0, *wolve_num = 0;

  static struct option long_options[] = {
      {"bear", no_argument, 0, 'b'},
      {"rabbits", required_argument, 0, 'r'},
      {"wolves",  required_argument, 0, 'w'},
      {"sum", no_argument, 0, 's'},
      {0, 0, 0, 0}
    };

  int option_index = 0;

  c = getopt_long (argc, argv, "br:w:s",
                       long_options, &option_index);
  std::cout << "В лесу было ";
  while (c != -1)
    {
      switch (c)
        {
        case 0:
          /*printf ("option %s", long_options[option_index].name);
          if (optarg)
            printf (" with arg %s", optarg);
          printf ("\n");*/
          break;

        case 'b':
	  if (bear == 0) {
          	bear = 1;
	  }
          break;

        case 'r':
	  if (rabbits == 0) {
          	rabbits = 1;
		rabbit_num = optarg;
		std::cout << rabbit_num << " кроликов ";
	  }
          break;

        case 'w':
	  if (wolves == 0) {
          	wolves = 1;
		wolve_num = optarg;
		std::cout << wolve_num << " волков ";
	  }	
	  break;

        case 's':
	  if (sum == 0) {
          	sum = 1;
	  }	
	  break;


        case '?':
          break;

        default:
          abort ();
        }

      c = getopt_long (argc, argv, "br:w:s",
                       long_options, &option_index);
    }
  
  if (bear == 1) {
	  std::cout << "\nТакже в лесу жил медведь.\n";
  }

  if (sum == 1) {
	int s = bear + atoi(wolve_num) + atoi(rabbit_num);
	std::cout << "\nВсего было " << s << " животных.\n";
  }

  if (optind < argc)
    {
      printf ("Неизвестные аргументы: ");
      while (optind < argc)
        printf ("%s ", argv[optind++]);
      putchar ('\n');
    }

  exit (0);
}
