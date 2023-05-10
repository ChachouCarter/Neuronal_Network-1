#include "OutputLayer.hpp"


// Constructeur
OutputLayer::OutputLayer(int Nbe, int Nbs) :  Proba(10,1)
{
    tailleInput = Nbe;
    tailleOutput = Nbs;
    result = -1;
}

// destructeur
OutputLayer::~OutputLayer()
{
}


Matrix OutputLayer::calculer_vecteur_de_probabilite(){
    
    for (int i = 0; i < 10; i++){
        if (etiq.weight[i][0]>sortie.weight[i][0]){
            Proba.weight[i][0] = (etiq.weight[i][0]-sortie.weight[i][0])*100;
        }
        else
        Proba.weight[i][0] = (sortie.weight[i][0]-etiq.weight[i][0])*100;
    }

}

void OutputLayer::obtenir_resultat()
{
    calculer_vecteur_de_probabilité()

}

Matrix OutputLayer::getProba(){
    return Proba;
}

Matrix OutputLayer::setProba(Matrix P){
    Proba = P;
}

 void calculerDelta(Layer L){
    double Ij;
	double dj;
	double s;
	double n=1;
	
	
	for (int i=0;i<arete.nbRows;i++)
	{
		for(int j=1;j<=arete.nbColumns;j++)
		{
			//Calcul de la somme pondérées des poids pour le neurone de sortis j
			Ij=L.arete.weight[j][0];
			s=0;
			for(int k=0;k<arete.nbRows;k++)
			{
				Ij=Ij+arete.weight[k][j]*sortie[j][0];
			}
            s=s+etiq.weight[j][0] - sortie.weight[j][0]; //x : sortie
			dj=dfonctionActivation(Ij)*s;
			d.weight[0][j]=dj; //d : vecteur des d_j
			if (j-1==0)
				delta.weight[i][j-1]=n*dj * L.biais.weight[j-1][0];
			else
				delta.weight[i][j-1]=n*dj*sortie.weight[i][0];
		}
	}
 }

