#ifndef __OUTPUTLAYER_HPP__
#define __OUTPUTLAYER_HPP__

#include "Layer.hpp"
#include "TrainingFunction.hpp"
#include "Matrix.hpp"


#include <vector>
using std::vector;

class OutputLayer : public Layer
{
private:
    //! Sortie du reseau
    int result;
    Matrix Proba;
    int tailleInput;
    int tailleOutput;

public:
    //! Constructeur
    OutputLayer(int Nbe, int Nbs);
    //! Destructeur
    ~OutputLayer();

    //! Creer la couche de sortie
    //void creer_derniere_couche(int tailleInput, int tailleOutput, TrainingFunction f);
    //! Prend en parametre une fonction correspondant a la fontion de perte du reseau, ici, l entropie croise
    //void //fonction_de_perte();
    //! Enregistre le resultat dans l attribut Proba
    
    Matrix getProba();
    Matrix calculer_vecteur_de_probabilite();
    Matrix getProba();
    Matrix setProba(Matrix P);
    void obtenir_resultat();
    void calculerDelta(Layer L);
     
};

#endif
