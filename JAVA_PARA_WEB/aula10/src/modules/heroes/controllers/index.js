import { HeroesRepository } from '../repositories/HeroRepository.js';
import { ListHeroesService } from '../services/ListHeroesService.js';
import { ListHeroesController } from './ListHeroController.js';
import { CreateHeroesService } from '../services/CreateHeroesService.js'
import { CreateHeroesController } from './CreateHeroController.js';
import { FindOneHeroesService } from '../services/FindOneHeroesService.js';
import { FindOneHeroesController } from './FindOneHeroController.js';
import { UpdateHeroService } from '../services/UpdateHeroService.js';
import { UpdateHeroController } from './UpdateHeroController.js';
import { DeleteHeroService } from '../services/DeleteHeroService.js';
import { DeleteHeroController } from './DeleteHeroController.js';

const heroesRepository = new HeroesRepository();

const createHeroService = new CreateHeroesService(heroesRepository);
export function createHeroController() {
    const createHeroController = new CreateHeroesController(
        createHeroService
    );
    return createHeroController;
}

const listHeroesService = new ListHeroesService(heroesRepository);
export function listHeroesController() {
    return new ListHeroesController(listHeroesService);
}

const findOneHeroesService = new FindOneHeroesService(heroesRepository);
export function findOneHeroesController() {
    return new FindOneHeroesController(findOneHeroesService);
}

const updateHeroService = new UpdateHeroService(heroesRepository);
export function updateHeroController() {
    return new UpdateHeroController(updateHeroService);
}

const deleteHeroService = new DeleteHeroService(heroesRepository);
export function deleteHeroController() {
    return new DeleteHeroController(deleteHeroService);
}