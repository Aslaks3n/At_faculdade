import java.util.Scanner;

public class Array1 {

    public static int calculaMedia(double a, int b, int c){
        a = b/c;
        System.out.printf("Média aritmética do array: " + a + "%n%n");
        return 0;}
    public static void main(String[] args){

    double mediaarit=0;
    int somatotal=0;
    int numeroatual=0; //numero de posicoes ocupadas no array
    int numeromax=10; //numero total de posicoes do array
    int[] intArray = new int[numeromax]; //construtor do array
    

        try{ //pega o erro caso o valor inserido supere o valor máximo de 10
    System.out.printf("Preencher o array com quantos valores? ");

    Scanner in = new Scanner(System.in);
    int numerodesejado = in.nextInt();
    
    for(int j=0; j<numerodesejado; j++){//gera valores para preencher o array
        import java.util.Scanner;

public class Array {

    public static int calculaMedia(double a, int b, int c){
        a = b/c;
        System.out.printf("Média aritmética do array: " + a + "%n%n");
        return 0;}
    public static void main(String[] args){

    double mediaarit=0;
    int somatotal=0;
    int numeroatual=0; //numero de posicoes ocupadas no array
    int numeromax=10; //numero total de posicoes do array
    int[] intArray = new int[numeromax]; //construtor do array
    

        try{ //pega o erro caso o valor inserido supere o valor máximo de 10
    System.out.printf("Preencher o array com quantos valores? ");

    Scanner in = new Scanner(System.in);
    int numerodesejado = in.nextInt();
    
    for(int j=0; j<numerodesejado; j++){//gera valores para preencher o array
        intArray[j]=(4+j)*7;
        numeroatual=numeroatual+1;
        somatotal += intArray[j];
        //mediaarit = somatotal/numerodesejado;
    }
    
    
    System.out.printf("||------------------------------------------||%n%n");
    System.out.printf("Array preenchido: { ");

    for(int i=0;i<numeromax;i++){//imprime os valores contidos no array
        System.out.printf("%d ", intArray[i]);
    } 

    System.out.printf(" }%n%n");
    System.out.printf("Número total de posições do array: " + numeromax + "%n");
    System.out.printf("Número de posições ocupadas no array: " + numeroatual + "%n");
    calculaMedia(mediaarit,somatotal,numerodesejado);
    System.out.printf("||------------------------------------------||");
    in.close();

}
catch (Exception e){
    
        System.out.print("O valor desejado excede o valor máximo do array!");
        
    
}
}
}   
	
        numeroatual=numeroatual+1;
        somatotal += intArray[j];
        //mediaarit = somatotal/numerodesejado;
    }
    
    
    System.out.printf("||------------------------------------------||%n%n");
    System.out.printf("Array preenchido: { ");

    for(int i=0;i<numeromax;i++){//imprime os valores contidos no array
        System.out.printf("%d ", intArray[i]);
    } 

    System.out.printf(" }%n%n");
    System.out.printf("Número total de posições do array: " + numeromax + "%n");
    System.out.printf("Número de posições ocupadas no array: " + numeroatual + "%n");
    calculaMedia(mediaarit,somatotal,numerodesejado);
    System.out.printf("||------------------------------------------||");
    in.close();

}
catch (Exception e){
    
        System.out.print("O valor desejado excede o valor máximo do array!");
        
    
}
}
}   
	