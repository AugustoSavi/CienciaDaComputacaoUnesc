import { useState } from 'react'
import { Container, Button, Col, Form, Row } from 'react-bootstrap'
import Table from 'react-bootstrap/Table';
import { AiFillDelete, AiFillEdit } from 'react-icons/ai'


export default function Home() {
  const modoArCondicionado = {
    VENTILAR: { descricao: 'ventilar' },
    REFRIGERAR: { descricao: 'refrigerar' },
    AQUECER: { descricao: 'aquecer' }
  }
  const initialState = {
    id: null,
    descricao: '',
    temperatura: 16,
    modo: '',
    velocidade: 1
  }
  const [count, setCount] = useState(1);
  const [values, setValues] = useState(initialState);
  const [cadastroShow, setCadastroShow] = useState(false)
  const handleChange = (event) => {
    setValues({
      ...values,
      [event.target.name]: event.target.value
    });
  };

  const [arCondicionados, setArCondicionados] = useState([]);

  function save() {
    if (values.id) {
      setArCondicionados(arCondicionados.map((arCondicionado) => {
        if (arCondicionado.id === values.id) {
          arCondicionado.descricao = values.descricao;
          arCondicionado.temperatura = values.temperatura;
          arCondicionado.modo = values.modo;
          arCondicionado.velocidade = values.velocidade;
        }
        return arCondicionado;
      }))
    } else {
      values.id = count;
      setArCondicionados(array => ([...array, values]));
      setCount(count + 1);
    }
    setValues(initialState);
  }

  function deleteArCondicionado(id) {
    setArCondicionados(arCondicionados.filter((element) => {
      return element.id != id
    }));
  }

  function isFormValid() {
    return values.descricao && values.modo && values.temperatura && values.velocidade;
  }

  return (
    <Container className="md-container">
      <Container>
        <h1 className='text-center m-4'>
          Controle de ar condicionados
        </h1>
        <Container>

          <Table striped>
            <thead>
              <tr>
                <th className='text-center'>id</th>
                <th className='text-center'>Descrição</th>
                <th className='text-center'>Temperatura</th>
                <th className='text-center'>Modo</th>
                <th className='text-center'>Velocidade</th>
                <th></th>
              </tr>
            </thead>
            <tbody>
              {
                arCondicionados.map((arCondicionado) => {
                  return (
                    <tr key={arCondicionado.id}>
                      <td className='text-center'>{arCondicionado.id}</td>
                      <td className='text-center'>{arCondicionado.descricao}</td>
                      <td className='text-center'>{arCondicionado.temperatura}</td>
                      <td className='text-center'>{modoArCondicionado[arCondicionado.modo].descricao || ''}</td>
                      <td className='text-center'>{arCondicionado.velocidade}</td>
                      <td>
                        <Button
                          className='mx-3'
                          title='editar registro'
                          onClick={() => { setValues(arCondicionado); setCadastroShow(true) }}
                        >
                          <AiFillEdit />
                        </Button>
                        <Button
                          variant="danger"
                          title='excluir registro'
                          onClick={() => deleteArCondicionado(arCondicionado.id)}>
                          <AiFillDelete />
                        </Button>
                      </td>
                    </tr>
                  );
                })
              }
            </tbody>
          </Table>
        </Container>
        {!cadastroShow ? (
          <Row className='justify-content-end'>
            <Button
              as={Col} md="4"
              title='adicionar ar condicionado'
              variant="success"
              className='mb-4'
              onClick={() => setCadastroShow(true)}>
              + Ar condicionado
            </Button>
          </Row>
        ) : null}

        {cadastroShow ? (
          <>
            <Form>
              <Row className="mb-3">
                <Form.Group as={Col} md="4">
                  <Form.Label>Descrição</Form.Label>
                  <Form.Control
                    type="text"
                    required
                    placeholder="Descrição"
                    maxLength={50}
                    onChange={handleChange}
                    name="descricao"
                    value={values.descricao}
                  />
                </Form.Group>

                <Form.Group as={Col} md="2">
                  <Form.Label>Temperatura</Form.Label>
                  <Form.Control
                    type="number"
                    placeholder="Temperatura"
                    onChange={handleChange}
                    name="temperatura"
                    value={values.temperatura}
                    required
                    min={16}
                    max={30}
                  />
                </Form.Group>

                <Form.Group as={Col} md="4">
                  <Form.Label>Modo</Form.Label>
                  <Form.Control
                    required
                    as="select"
                    placeholder="Modo"
                    onChange={handleChange}
                    name="modo"
                    value={values.modo}
                  >
                    <option value="">Selecione o modo</option>
                    <option value="VENTILAR">ventilar</option>
                    <option value="REFRIGERAR">refrigerar</option>
                    <option value="AQUECER">aquecer</option>
                  </Form.Control>

                </Form.Group>

                <Form.Group as={Col} md="2">
                  <Form.Label>Velocidade</Form.Label>
                  <Form.Control
                    type="number"
                    required
                    placeholder="Velocidade"
                    onChange={handleChange}
                    name="velocidade"
                    value={values.velocidade}
                    min={1}
                    max={3}
                  />
                </Form.Group>
              </Row>
            </Form>
            <Row className='m-6 justify-content-around'>
              <button
                disabled={!isFormValid()}
                className='col-4 btn btn-success'
                onClick={() => { save() }}>
                Salvar
              </button>
              <button
                className='col-4 btn btn-danger'
                onClick={() => { setCadastroShow(false) }}>
                Fechar
              </button>
            </Row>
          </>
        ) : null}
      </Container>
    </Container>
  )
}
