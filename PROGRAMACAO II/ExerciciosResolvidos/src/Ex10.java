/*Elabore um algoritmo que imprima todos os números pares de 500 a
250 e também a soma destes números.*/
public class Ex10 {
    public static void main(String[] args) {
       int Soma=0;
        for(int i=500;i>249;i--){
            if(i%2==0){
                System.out.println(""+i);
                 Soma=Soma+i;
            }
        }
        System.out.println("Soma dos numeros pares:"+Soma);
        
    }
    
}

