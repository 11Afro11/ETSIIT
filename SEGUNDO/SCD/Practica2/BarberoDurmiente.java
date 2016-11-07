
import java.util.Random;
import monitor.*;

class Barberia extends AbstractMonitor
{  
	private Condition barbero = makeCondition();
	private Condition silla = makeCondition();
	private Condition barberia = makeCondition();
	private boolean hay_clientes = false;
	
	//invcado por los clientes para cortarse el pelo
	public void cortarPelo(int cliente)
	{
	  enter();
	  
	  	System.out.println("Entra cliente "+cliente);
	  	
	  	if(hay_clientes){
	  		System.out.println("El cliente "+cliente+ " espera");	
	  		barberia.await();	//bloqueamos la sala
	  	}

	  	barbero.signal();	//despertamos al barbero

	  	hay_clientes = true;	// sala de espera llena

	  	System.out.println("El cliente "+cliente+" se corta el pelo");

	  	silla.await();	//bloqueas la silla

	  leave();
	}
	//invocado por el barbero para esperar (si procede) a un nuevo cliente y sentarlo para el corte
	public void siguienteCliente()
	{
	  enter();
	  	if(barberia.isEmpty() && silla.isEmpty()){	//comprobamos si la barberia esta vacía
	  		System.out.println("El barbero duerme"); 
	  		hay_clientes = false;	//no hay clientes
	  		barbero.await();	//barbero duerme
	  	}
	  	System.out.println("El barbero llama al siguente cliente");
	  	barberia.signal();	//desbloquea barberia
	  leave();
	}
	//invocado por el barbero para indicar que ha terminado de cortar el pelo
	public void finCliente()
	{
	  enter();

	  	System.out.println("El barbero ha ternimado");
	  	silla.signal();	//desbloquea la silla
	  	

	  leave();
	}
}

class Cliente implements Runnable
{
	public Thread thr;
	private Barberia barberia;
	private int num_cliente;

	//constructor de cliente
	public Cliente(Barberia barberia, int cliente){
		this.barberia = barberia;
		num_cliente = cliente;
		thr = new Thread(this, "Cliente "+ cliente);
	}
	
	public void run()
	{
		while(true)
		{
			barberia.cortarPelo(num_cliente);//el cliente espera (si procede) y se corta el pelo
			aux.dormir_max( 2000 );// el cliente esta fuera de la barberia un tiempo
		}
	}
}


class Barbero implements Runnable
{
	public Thread thr;
	private Barberia barberia;

	//constructor de barbero
	public Barbero(Barberia barberia){
		this.barberia = barberia;
		thr = new Thread(this, "Barbero");
	}
	public void run	()
	{
		while(true) 
		{
			barberia.siguienteCliente();
			aux.dormir_max( 2500 );	//el barbero esta cortando el pelo
			barberia.finCliente();
		}
	}
}


class BarberoDurmiente{
	public static void main(String[] args){
		//comprobamos el numero de argumentos
		if(args.length != 1) {
	        System.out.println("Uso: <numero de clientes>");
	        return ;
	    }
	    //hacemos un casting al numero de clientes
	    int num_cliente = Integer.parseInt(args[0]);

	    //creamos e inicializamos
	    Barberia barberia = new Barberia();
	    Barbero barbero = new Barbero(barberia);
	    barbero.thr.start();

	    Cliente[] clientes = new Cliente[num_cliente];

	    for(int i = 0; i < num_cliente; i++){
	    	clientes[i] = new Cliente(barberia, i);
	    	clientes[i].thr.start();
	    }

	}
}