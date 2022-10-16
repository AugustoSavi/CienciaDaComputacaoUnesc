import mongoose from 'mongoose';

try {
    await mongoose.connect('mongodb://root:example@localhost:27017/computadores?authSource=admin');
} catch (error) {
    console.log(error);
}

mongoose.connection.on('connected', () => {
    console.log('mongo connectado');
});