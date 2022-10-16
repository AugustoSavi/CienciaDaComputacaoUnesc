import mongoose from 'mongoose';
const { Schema } = mongoose;

const ComputadorSchema = new Schema({
    hostname: String,
    processador: String,
    memoria: String,
    armazenamento: String,
    estado: String,
});

export const Computador = mongoose.model('computador', ComputadorSchema);