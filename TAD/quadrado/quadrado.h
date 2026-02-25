typedef struct quadrado* Quadrado;

Quadrado cria_quadrado(float l);
void destruir_quadrado(Quadrado q);
float acessa_lado(Quadrado q);
int altera_lado(Quadrado q, float l);
float calculo_area(Quadrado q);
float calculo_perimetro(Quadrado q);