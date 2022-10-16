import { ComputadoresRepository } from '../repositories/ComputadorRepository.js';
import { ListComputadoresService } from '../services/ListComputadoresService.js';
import { ListComputadoresController } from './ListComputadoresController.js';
import { CreateComputadorService } from '../services/CreateComputadorService.js'
import { CreateComputadorController } from './CreateComputadorController.js';
import { FindOneComputadorService } from '../services/FindOneComputadorService.js';
import { FindOneComputadorController } from './FindOneComputadorController.js';
import { UpdateComputadorService } from '../services/UpdateComputadorService.js';
import { UpdateComputadorController } from './UpdateComputadorController.js';
import { DeleteComputadorService } from '../services/DeleteComputadorService.js';
import { DeleteComputadorController } from './DeleteComputadorController.js';

const computadoresRepository = new ComputadoresRepository();

const createComputadorService = new CreateComputadorService(computadoresRepository);
export function createComputadorController() {
    const createComputadorController = new CreateComputadorController(
        createComputadorService
    );
    return createComputadorController;
}

const listComputadoresService = new ListComputadoresService(computadoresRepository);
export function listComputadoresController() {
    return new ListComputadoresController(listComputadoresService);
}

const findOneComputadorService = new FindOneComputadorService(computadoresRepository);
export function findOneComputadorController() {
    return new FindOneComputadorController(findOneComputadorService);
}

const updateComputadorService = new UpdateComputadorService(computadoresRepository);
export function updateComputadorController() {
    return new UpdateComputadorController(updateComputadorService);
}

const deleteComputadorService = new DeleteComputadorService(computadoresRepository);
export function deleteComputadorController() {
    return new DeleteComputadorController(deleteComputadorService);
}