import { HeroesRepository } from '../repositories/HeroRepository.js';

import { ListHeroesService } from '../services/ListHeroesService.js';
import { ListHeroesController } from './ListHeroController.js';

import { CreateHeroesService } from '../services/CreateHeroesService.js'
import { CreateHeroesController } from './CreateHeroController.js';

import { FindOneHeroesService } from '../services/FindOneHeroesService.js';
import { FindOneHeroesController } from './FindOneHeroController.js';

import { UpdateHeroService } from '../services/UpdateHeroService.js';
import { UpdateHeroController } from './UpdateHeroController.js';

const heroesRepository = new HeroesRepository();

// Criação de hero
const createHeroService = new CreateHeroesService(heroesRepository);
export function createHeroController() {
    const createHeroController = new CreateHeroesController(
        createHeroService
    );
    return createHeroController;
}

// Listagem de heroes
const listHeroesService = new ListHeroesService(heroesRepository);
export function listHeroesController() {
    return new ListHeroesController(listHeroesService);
}

// Encontrar Hero por id
const findOneHeroesService = new FindOneHeroesService(heroesRepository);
export function findOneHeroesController() {
    return new FindOneHeroesController(findOneHeroesService);
}

// Update Hero por id
const updateHeroService = new UpdateHeroService(heroesRepository);
export function updateHeroController() {
    return new UpdateHeroController(updateHeroService);
}
