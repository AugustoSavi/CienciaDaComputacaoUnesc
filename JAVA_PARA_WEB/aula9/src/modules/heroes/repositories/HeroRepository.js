import {Hero} from '../entities/Hero.js';

class HeroesRepository {

    async create({ name, slug , age}){
        const hero = new Hero({
            name,
            slug,
            age
        });

        return await hero.save();
    }

    async list(){
        const heroes = await Hero.find({});
        return heroes;
    }

    async findByName(name){
        const hero = Hero.findOne({ name });
        return hero;
    }

    async findById(id){
        const hero = await Hero.findById(id).exec();
        return hero;
    }

    async findByIdAndUpdate(id, { name, slug, age}){
        const hero = await Hero.findByIdAndUpdate(id, {name, slug, age});
        return hero
    }
}

export { HeroesRepository };