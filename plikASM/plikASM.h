#ifdef PLIKASM_EXPORTS
#define PLIKASM_API __declspec(dllexport)
#else
#define PLIKASM_API __declspec(dllimport)
#endif





extern "C"  int* _stdcall sort(int* arr, int amount);