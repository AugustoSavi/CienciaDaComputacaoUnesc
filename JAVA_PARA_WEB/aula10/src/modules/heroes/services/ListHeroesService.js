class ListHeroesService {
    heroesRepository;

    constructor(heroesRepository) {
        this.heroesRepository = heroesRepository;
    }

    execute() {
        return this.heroesRepository.list();
    }
}

export { ListHeroesService };