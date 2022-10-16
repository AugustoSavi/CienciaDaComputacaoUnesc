import { useState, useEffect } from 'react';
import { Container, Button, Row, Spinner, Table } from 'react-bootstrap';
import { AiFillDelete, AiFillEdit } from 'react-icons/ai';
import { useRouter } from 'next/router';
import api from '../services/api';


export default function Home() {
  const [data, setData] = useState([]);
  const [loading, setLoading] = useState(true);
  const router = useRouter();

  useEffect(() => {
    getData();
  }, []);

  function getData(){
    setLoading(true);
    api.get('computador')
    .then((response) => {
      setData(response.data);
      setLoading(false);
    });
  }

  function handleDelete(id) {
    api.delete(`computador/${id}`).then(() => {
      getData();
    });
  }

  function handleRoute(href) {
    router.push(href)
  }

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
              onClick={()=> handleRoute("/computador")}
              title='adicionar computador'
              variant="success"
              className='mb-4'>
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
                            onClick={() => handleRoute(`/computador/${computador._id}`)}
                            className='mx-3'
                            title='editar registro'
                          >
                            <AiFillEdit />
                          </Button>
                          <Button
                            variant="danger"
                            title='excluir registro'
                            onClick={() => { handleDelete(computador._id) }}>
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
