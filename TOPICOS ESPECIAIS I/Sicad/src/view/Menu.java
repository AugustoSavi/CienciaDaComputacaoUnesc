package view;

import java.awt.*;

import java.awt.event.*;
import java.text.ParseException;

import javax.swing.*;

import model.UsuarioModel;

@SuppressWarnings("serial")
public class Menu extends JFrame {

	// Paineis e items do menu
	public JDesktopPane desktopPane;
	private JMenuBar menuBar;
	private JMenu  matricular, sistema, cadastro, processos, utilitarios;
	private JMenuItem alunos, usuarios, sair, cadaluno, modalidades, backupRestore;
	// Classes/frames
	private Usuarios fUsuario;
	private Sair fSair;
	private CadastroAlunos fCadastroAlunos;
	private ModalidadesGraduacoes fModalidades;
	private MatricularAlunos fMatricularAlunos;
	
	private AdicionarModalidades fAdicionarModalidades;

	private ControleAlunos fControleAlunos;
	private BuscarAluno fBuscarAluno;
	private BackupRestore fBackupRestore;
	private String perfil, usuario;

	private int janelaAberta = 0;

	public Menu(String Perfil, String Usuario) {
		usuario = Usuario;
		perfil = Perfil;

		try {
			UIManager.setLookAndFeel("javax.swing.plaf.nimbus.NimbusLookAndFeel");
		} catch (ClassNotFoundException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		} catch (InstantiationException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		} catch (IllegalAccessException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		} catch (UnsupportedLookAndFeelException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}

		desktopPane = new JDesktopPane();

		usuarios = new JMenuItem("Usuarios");
		usuarios.addActionListener(new ActionListener() {

			public void actionPerformed(ActionEvent evt) {

				fecharJanelaAberta();
				janelaAberta = 1;
				
				try {
				fUsuario = new Usuarios();
				} catch (Exception e) {
					// TODO: handle exception
					e.printStackTrace();
				}
				desktopPane.add(fUsuario);
				fUsuario.setVisible(true);
				fUsuario.setPosicao();
			}
		});

		sair = new JMenuItem("Sair");
		sair.addActionListener(new ActionListener() {

			public void actionPerformed(ActionEvent evt) {

				fecharJanelaAberta();
				janelaAberta = 2;

				fSair = new Sair();
				fSair.setVisible(true);
				desktopPane.add(fSair);
			}
		});

		cadaluno = new JMenuItem("Alunos");
		cadaluno.addActionListener(new ActionListener() {

			public void actionPerformed(ActionEvent evt) {

				fecharJanelaAberta();
				janelaAberta = 3;

				try {
					fCadastroAlunos = new CadastroAlunos();
				} catch (ParseException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				desktopPane.add(fCadastroAlunos);
				fCadastroAlunos.setVisible(true);
				fCadastroAlunos.setPosicao();
				
			}
		});
		

		modalidades = new JMenuItem("Modalidades");
		modalidades.addActionListener(new ActionListener() {

			public void actionPerformed(ActionEvent evt) {

				fecharJanelaAberta();
				janelaAberta = 4;

				fModalidades = new ModalidadesGraduacoes();
				desktopPane.add(fModalidades);
				fModalidades.setVisible(true);
				fModalidades.setPosicao();
				
			}
		});


		alunos = new JMenuItem("Alunos");
		alunos.addActionListener(new ActionListener() {

			public void actionPerformed(ActionEvent evt) {

				fecharJanelaAberta();
				janelaAberta = 5;

				fMatricularAlunos = new MatricularAlunos();
				desktopPane.add(fMatricularAlunos);
				fMatricularAlunos.setVisible(true);
				fMatricularAlunos.setPosicao();
				
			}
		});




		matricular = new JMenu("Matricular");
		matricular.addActionListener(new ActionListener() {

			public void actionPerformed(ActionEvent evt) {

				fecharJanelaAberta();
				janelaAberta = 6;

				fMatricularAlunos = new MatricularAlunos();
				fMatricularAlunos.setVisible(true);
				desktopPane.add(fMatricularAlunos);
			}
		});

		
		backupRestore = new JMenuItem("Backup");
		backupRestore.addActionListener(new ActionListener() {

			public void actionPerformed(ActionEvent evt) {

				fecharJanelaAberta();
				janelaAberta = 19;

				fBackupRestore = new BackupRestore();
				desktopPane.add(fBackupRestore);
				fBackupRestore.setVisible(true);
				fBackupRestore.setPosicao();
				
			}
		});

		setContentPane(desktopPane);

		menuBar = new JMenuBar();
		sistema = new JMenu("Sistema");

		if(perfil.equals("Completo"))
		sistema.add(usuarios);
		sistema.add(sair);
		menuBar.add(sistema);

		cadastro = new JMenu("Cadastros");

		
		cadastro.add(cadaluno);
		cadastro.add(modalidades);

		

		if(perfil.equals("Cadastral") || perfil.equals("Completo"))
		menuBar.add(cadastro);

		processos = new JMenu("Processos");


		matricular.add(alunos);
		
		
		if(perfil.equals("Matricular") || perfil.equals("Completo"))
		processos.add(matricular);
		

		utilitarios = new JMenu("Utilitarios");
		utilitarios.add(backupRestore);

		menuBar.add(utilitarios);


		setJMenuBar(menuBar);
		setTitle("Sicad");
		setExtendedState(JFrame.MAXIMIZED_BOTH);
		setLocationRelativeTo(null);
		setBackground(null);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setResizable(true);
		setContentPane(CreateContentPane());
		setVisible(true);
		FramePrincipal();
	}

	public Container CreateContentPane() {

		JPanel contentPane = new JPanel(new BorderLayout());
		desktopPane = new JDesktopPane() {
			Image im = (new ImageIcon("Images/background/backgound.jpg")).getImage();

			public void paintComponent(Graphics g) {
				g.drawImage(im, 0, 0, getWidth(), getHeight(), this);

			}
		};

		contentPane.setOpaque(true);
		contentPane.add(desktopPane);
		return contentPane;
	}

	public void FramePrincipal() {

		fControleAlunos = new ControleAlunos(this);
		desktopPane.add(fControleAlunos);
		fControleAlunos.setVisible(true);
	
		
	}

	public void mostrarJanela(boolean o) {

		setVisible(o);
	}

	private void fecharJanelaAberta() {
		switch (janelaAberta) {
		case 1:
			fUsuario.dispose();
			break;
		case 2:
			fSair.dispose();
			break;

		case 3:
			fCadastroAlunos.dispose();
			break;

		case 4:
			fModalidades.dispose();
			break;

		case 5:
			fMatricularAlunos.dispose();
			break;

		case 6:
			fMatricularAlunos.dispose();
			break;

		case 7:
			
			break;

		case 9:
			
			break;
		case 10:
			
			break;
		case 12:
			
			break;
		case 13:
			
			break;
		case 14:
			
			break;
		case 15:
			
			break;
		case 16:
			fAdicionarModalidades.dispose();
			break;
		case 17:
			
			break;
		case 18:
			
			break;
		case 20:
			fBuscarAluno.dispose();
			break;

		default:
			break;
		}
	}

	public static void main(String args[])	{

		new Menu("Completo", "admin");
	}
}