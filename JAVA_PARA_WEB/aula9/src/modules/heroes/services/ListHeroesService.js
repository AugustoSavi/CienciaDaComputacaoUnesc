class ListHeroesService {
    heroesRepository;

    constructor(heroesRepository) {
        this.heroesRepository = heroesRepository;
        console.log("ListHeroService criado");
    }

    execute() {
        return this.heroesRepository.list();
    }
}

export { ListHeroesService };