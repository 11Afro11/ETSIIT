import java.util.Random;
import monitor.*;

class Estanco extends AbstractMonitor
{
	private int vacio;	//mostrador vacio =-1
	private Condition sem_estanquero = makeCondition();	//condicion estanquero
	private Condition[] sem_fumador = new Condition[3];	//condicion Fumador

	//constructor del monitor
	public Estanco()
	{
		this.vacio = -1;
		for( int i = 0; i < 3; i++){
			sem_fumador[i] = makeCondition();
		}
	}

	//metodo que consume ingrediente
	public void obtenerIngrediente(int ingrediente)
	{
		enter();

			if(ingrediente != vacio){
				sem_fumador[ingrediente].await();
			}
			System.out.println("Fumador "+ ingrediente+ " sale a fumar\n");
			vacio = -1;
			sem_estanquero.signal();

		leave();
	}

	//metodo que crea el ingrediente
	public void ponerIngrediente(int ingrediente)
	{
		enter();
			vacio = ingrediente;
			System.out.println("Creado "+ ingrediente+ " en mostrador\n");
			sem_fumador[ingrediente].signal();
		leave();
	}

	//metodo que espera mientras fuma
	public void esperarRecogida()
	{
		enter();
			if(vacio != -1)
			{
				sem_estanquero.await();
			}
		leave();
	}
}
	
//clase estanquero
class Estanquero implements Runnable
{
	Estanco estanco;
	Thread thr;

	public Estanquero(Estanco est)
	{
		estanco = est;
		thr = new Thread(this, "Estanquero");
	}

	public void run()
	{
		try
		{
			int ingrediente;
			while(true)
			{
				ingrediente = (int) (Math.random() * 3.0);
				estanco.ponerIngrediente(ingrediente);
				estanco.esperarRecogida();
			}
		}
		catch( Exception e ) 
	    { 
	      System.err.println("Excepcion en main: " + e);
	    }
	}
}

//clase fumador
class Fumador implements Runnable
{
	Estanco estanco;
	Thread thr;
	int ingrediente;

	public Fumador(Estanco est, int ingr)
	{
		estanco = est;
		ingrediente = ingr;
		thr = new Thread(this, "Fumador");
	}

	public void run()
	{
		try
		{
			while(true)
			{
				estanco.obtenerIngrediente(ingrediente);
				aux.dormir_max(2000);
			}
		}
		catch( Exception e ) 
	    { 
	      System.err.println("Excepcion en main: " + e);
	    }
	}
}

//auxiliar para fumar
class aux
{
  static Random genAlea = new Random() ;

  static void dormir_max( int milisecsMax )
  { 
    try
    { 
      Thread.sleep( genAlea.nextInt( milisecsMax ) ) ;
    } 
    catch( InterruptedException e )
    { 
      System.err.println("sleep interumpido en 'aux.dormir_max()'");
    }
  }
}

//MAIN
class Fumadores
{
	public static void main(String[] args)
	{
		Estanco estanco = new Estanco();
		Estanquero estanquero = new Estanquero(estanco);
		Fumador [] fumador = new Fumador[3];


		for(int i = 0; i < 3; i++){
			fumador[i] = new Fumador(estanco, i);
		}

		estanquero.thr.start();
		for(int i = 0; i < 3; i++){
			fumador[i].thr.start();
		}
	}
}