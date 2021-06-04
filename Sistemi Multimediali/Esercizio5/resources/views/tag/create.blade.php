@extends('layouts.app')

@section('page_title', 'I Miei Hobby - Creazione Tag')
@section('page_description', 'Crea un nuovo Tag qui')

@section('content')
    <div class="container">
        <div class="row justify-content-center">
            <div class="col-md-12">
                <div class="card">
                    <div class="card-header"><h1 class="m-0">Crea un nuovo tag</h1></div>
                    <div class="card-body">
                        <form action="/tag" method="post">
                            @csrf
                            <div class="form-group">
                                <label for="name">Nome</label>
                                <input type="text" class="form-control{{$errors->has('name')? ' border-danger':''}}"
                                       id="name"
                                       name="name"
                                       placeholder="Inserisci qui il nome del tag" value={{old('name')}}>
                                <small class="alert-danger">{{$errors->first('name')}}</small>
                            </div>
                            <div class="form-group">
                                <label for="style">Colore del Tag</label>
                                <input type="color" id="style" name="color">
                            </div>
                            <input class="btn btn-primary mt-4" type="submit" value="Salva il tag">
                        </form>
                        <a class="btn btn-primary float-right" href="{{\Illuminate\Support\Facades\URL::previous()}}"><i
                                class="fas fa-arrow-circle-up"></i>
                            Indietro</a>
                    </div>
                </div>
            </div>
        </div>
    </div>
@endsection
