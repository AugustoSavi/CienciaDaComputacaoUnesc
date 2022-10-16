import { Container, Button, Spinner, Form, Row, Col } from 'react-bootstrap'
import { useState, useEffect } from 'react'
import { useRouter } from 'next/router';
import api from '../../services/api';

const initialState = {
    _id: '',
    hostname: '',
    processador: '',
    memoria: '',
    armazenamento: '',
    estado: ''
};

const Computador = () => {
    const router = useRouter()
    const id = router.query && router.query.id && router.query.id[0] ? router.query.id[0] : null;
    const [values, setValues] = useState(initialState);
    const [loading, setLoading] = useState(false);

    useEffect(() => {
        if (id) {
            api.get(`computador/${id}`)
                .then((response) => {
                    setValues(response.data);
                    setLoading(false);
                });
        }
    }, [id])

    const handleChange = (event) => {
        setValues({
            ...values,
            [event.target.name]: event.target.value
        });
    };

    const handleSubmit = (event) => {
        event.preventDefault();
        if (values._id) {
            return api.put(`computador/${id}`, values).then(() => { router.push("/") })
        } else {
            return api.post(`computador`, values).then(() => { router.push("/") })
        }
    }

    if (loading) return <Spinner />;

    return (
        <Container className="md-container">
            <Container>
                <h1 className='text-center m-4'>
                    {id ? "Edição do computador" : "Cadastro de computadores"}
                </h1>
                <Form className='justify-content-center' onSubmit={handleSubmit}>
                    <Form.Group className="mb-3" controlId="formBasicId">
                        <Form.Label>ID</Form.Label>
                        <Form.Control
                            onChange={handleChange}
                            value={values._id}
                            type="text"
                            placeholder=""
                            name='_id'
                            readOnly />
                    </Form.Group>

                    <Form.Group className="mb-3" controlId="formBasicPassword">
                        <Form.Label>hostname</Form.Label>
                        <Form.Control
                            onChange={handleChange}
                            value={values.hostname}
                            type="text"
                            name="hostname"
                            placeholder="hostname" />
                    </Form.Group>

                    <Form.Group className="mb-3" controlId="formBasicPassword">
                        <Form.Label>processador</Form.Label>
                        <Form.Control
                            onChange={handleChange}
                            value={values.processador}
                            type="text"
                            name="processador"
                            placeholder="processador" />
                    </Form.Group>

                    <Form.Group className="mb-3" controlId="formBasicPassword">
                        <Form.Label>memoria</Form.Label>
                        <Form.Control
                            onChange={handleChange}
                            value={values.memoria}
                            type="text"
                            name="memoria"
                            placeholder="memoria" />
                    </Form.Group>

                    <Form.Group className="mb-3" controlId="formBasicPassword">
                        <Form.Label>armazenamento</Form.Label>
                        <Form.Control
                            onChange={handleChange}
                            value={values.armazenamento}
                            type="text"
                            name="armazenamento"
                            placeholder="armazenamento" />
                    </Form.Group>

                    <Form.Group className="mb-3" controlId="formBasicPassword">
                        <Form.Label>estado</Form.Label>
                        <Form.Control
                            onChange={handleChange}
                            value={values.estado}
                            type="text"
                            name="estado"
                            placeholder="estado" />
                    </Form.Group>

                    <Row className='justify-content-end'>
                        <Button className='col-4' variant="success" type="submit">
                            Salvar
                        </Button>
                    </Row>
                </Form>
            </Container>
        </Container>
    )
}

export default Computador