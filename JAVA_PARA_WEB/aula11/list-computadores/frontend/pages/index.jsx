import { useState, useEffect } from 'react'
import { Container, Button, Col, Form, Row, Spinner } from 'react-bootstrap'
import Table from 'react-bootstrap/Table';
import { AiFillDelete, AiFillEdit } from 'react-icons/ai'
import api from '../services/api';


export default function Home() {
  const [data, setData] = useState([]);
  const [loading, setLoading] = useState(true);


  useEffect(() => {
    api.get('computador')
      .then((response) => {
        setData(response.data);
        setLoading(false);
      });
  }, []);

  if (loading) return <Spinner />;

  return (
    <Container className="md-container">
      <Container>
        <h1 className='text-center m-4'>
          Controle de computadores
        </h1>
        <Container>
          <Row className='justify-content-start'>
            <Button
              as={Col}
              md="2"
              title='adicionar copmutador'
              variant="success"
              className='mb-4'
              onClick={() => setCadastroShow(true)}>
              + Computador
            </Button>
          </Row>
          {loading ? <Row className='justify-content-center'><Spinner animation="border" /></Row> :
            <Table striped>
              <thead>
                <tr>
                  <th className='text-center'>id</th>
                  <th className='text-center'>hostname</th>
                  <th className='text-center'>processador</th>
                  <th className='text-center'>memoria</th>
                  <th className='text-center'>armazenamento</th>
                  <th className='text-center'>estado</th>
                  <th></th>
                </tr>
              </thead>
              <tbody>
                {
                  data.map((computador) => {
                    return (
                      <tr key={computador._id}>
                        <td className='text-center'>{computador._id}</td>
                        <td className='text-center'>{computador.hostname}</td>
                        <td className='text-center'>{computador.processador}</td>
                        <td className='text-center'>{computador.memoria}</td>
                        <td className='text-center'>{computador.armazenamento}</td>
                        <td className='text-center'>{computador.estado}</td>
                        <td>
                          <Button
                            className='mx-3'
                            title='editar registro'
                            onClick={() => { }}
                          >
                            <AiFillEdit />
                          </Button>
                          <Button
                            variant="danger"
                            title='excluir registro'
                            onClick={() => { }}>
                            <AiFillDelete />
                          </Button>
                        </td>
                      </tr>
                    );
                  })
                }
              </tbody>
            </Table>
          }
        </Container>
      </Container>
    </Container>
  )
}
