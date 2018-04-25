
int main(int argc, char * argv[])
{
  if (argc != 2)
    {
      cerr << "Formato " << argv[0] << " <num_elem>" << endl;
      return -1;
    }
  
  int n = atoi(argv[1]);
  
  int * T = new int[n];
  
  assert(T);

  srandom(time(0));

  for (int i = 0; i < n; i++)
    {
      T[i] = random();
    };

  high_resolution_clock::time_point tantes, tdespues;
  duration<double> transcurrido;

  tantes = high_resolution_clock::now();
 
  burbuja(T, n);
  
  tdespues = high_resolution_clock::now();

  transcurrido = duration_cast<duration<double>>(tdespues - tantes);
  cout << n << " "  << transcurrido.count() << endl;

  delete [] T;

  return 0;
};
