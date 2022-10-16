import { Computador } from '../entities/Computador.js';

class ComputadoresRepository {

    async create({ hostname, processador, memoria, armazenamento, estado }) {
        const computador = new Computador({
            hostname,
            processador,
            memoria,
            armazenamento,
            estado
        });

        return await computador.save();
    }

    async list() {
        const computadores = await Computador.find({});
        return computadores;
    }

    async findByHostname(hostname) {
        const computador = Computador.findOne({ hostname });
        return computador;
    }

    async findById(id) {
        const computador = await Computador.findById(id).exec();
        return computador;
    }

    async findByIdAndUpdate(id, { hostname, processador, memoria, armazenamento, estado }) {
        const computador = await Computador.findByIdAndUpdate(id, { hostname, processador, memoria, armazenamento, estado });
        return computador
    }

    async findByIdAndRemove(id) {
        const computador = await Computador.findByIdAndRemove(id);
        return computador
    }
}

export { ComputadoresRepository };