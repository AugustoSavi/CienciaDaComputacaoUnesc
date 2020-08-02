/* Elabore um algoritmo que imprima todos os números ímpares de 250 a
500 e também a soma destes números.*/
public class Ex8 {
    public static void main(String[] args) {
        
    int Soma = 0;
    
        for(int i=250;i<501;i++){
            if(i%2==1){
                System.out.println(""+i);
                Soma=Soma+i;
            } 
        }
        System.out.println("Soma dos numeros impares:"+Soma);
    }
    
}
